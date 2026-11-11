#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000000ll
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;
const int Maxn=2e6+5;
const int N=3e2+5;
int c,t,n,d,a[Maxn],cnt[Maxn],de[Maxn],mn=inf;
void dfs(int now,string s,int l,int r)
{
	if(now==r-l)
	{
		int lst=a[l],re=0;
		s+='1';
		// cout<<"!!! "<<l<<" "<<" "<<r<<" "<<s<<'\n';
		for(int i=1;i<=r-l;i++) 
		{
			if(s[i]=='1')
			{
				int now=a[l+i];
				if(a[l+i]-lst>d) return ;
				if(re<r-l) re++;
				lst=a[l+i];
			}
		}
		mn=min(mn,re);
		cnt[re]++;
		return ;
	}
	dfs(now+1,s+'0',l,r);
	dfs(now+1,s+'1',l,r);
}
void gowork()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=9)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{ 
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d) continue;
				fill(cnt+1,cnt+n+1,0);
				mn=inf;
				dfs(1," ",i,j);
				if(mn!=inf&&cnt[mn]==2)
				{
					ans++;
					// cout<<"??? "<<i<<" "<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=0;i<=n;i++) cnt[i]=0;
		return ;
	}
	bool flag=1;
	for(int i=1;i<n;i++) de[i]=a[i+1]-a[i];
	for(int i=2;i<n;i++) flag&=(de[i]==de[i-1]);
	if(flag)
	{
		int k=d/de[1];
		if(k<=1) cout<<0<<'\n';
		else
		{
			int re=2*k;
			cout<<max(0ll,n-re+1)<<'\n';
		} 
	}
	else cout<<0<<'\n';
	for(int i=1;i<=n;i++) de[i]=0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) gowork();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5	

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/

// 16