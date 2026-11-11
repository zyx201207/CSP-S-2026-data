#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int aaa[200010];
int s[200010]; 
int st[200010];
int n,m;
int ma=0;
void dfs(int gs,int ans,int dq)
{
	if(gs==m+1)
	{
		int anss=s[1];
		for(int i=2;i<=m;i++)
		{
			anss=anss&s[i];
		}
		ma=max(anss,ma);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==1)continue;
		else if(st[i]==0)
		{
			st[i]=1;
			s[gs]=aaa[i];
			dfs(gs+1,ans&aaa[i],i);
			s[gs]=0;
			st[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aaa[i]; 
	}
	dfs(1,aaa[1],1);
	cout<<ma;
	return 0;
} 
