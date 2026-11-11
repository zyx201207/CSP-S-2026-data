#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
int n,m,a[500005],cnt[500005],ans[300005],stk[500005],top=0;
bool instk[300005];
bool f=true;
void solve1()
{
	for(int i=n;i>=1;i--)
	{
		stk[top++]=i;
		cnt[i]=i;
		if(instk[a[i]])
		{
			cnt[i]=0,--top;
			while(top>0&&a[stk[top-1]]!=a[i]) instk[a[stk[--top]]]=0,cnt[stk[top]]-=i;
		}
		instk[a[i]]=1;
		for(int j=1;j<=n;j++) cout<<cnt[j]<<" ";cout<<"\n";
	}
	for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],cnt[i]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		vector<int> ins(m+1,0),s;
		for(int j=i;j<=n;j++)
		{
			if(ins[a[j]])
			{
				while(!s.empty()&&a[s[s.size()-1]]!=a[j]) ins[a[s[s.size()-1]]]=0,s.pop_back();
				if(!s.empty()) s.pop_back();
			}
			ins[a[j]]=1;
			s.push_back(j);
		}
		for(int i:s) cnt[i]++;
	}
	for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],cnt[i]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i-1]>a[i]) f=false;
	}
	if(f) solve1();
	else solve2();
	return 0;
}
