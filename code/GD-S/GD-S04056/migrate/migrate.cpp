#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long n,d;
long long x[maxn];
int lst[maxn];
vector<int> v[maxn];
long long dp[maxn],f[maxn];
bool vis[maxn];
void DP(int id)
{
	if(dp[id]!=-1)
	{
		return ;
	}
	dp[id]=1;
	for(int i:v[id])
	{
		DP(i);
		if(!vis[i]&&i!=id)dp[id]+=dp[i];
	}
}
void F(int id)
{
	if(f[id]!=-1)
	{
		return ;
	}
	if(lst[id]==id)
	{
		f[id]=1;
		return ;
	}
	f[id]=lst[id]-max(lst[id-1],id)+1;
//	if(lst[id]==n)return ;
	for(int i=max(lst[lst[id]-1],lst[id])+1;i<=lst[lst[id]];i++)
	{
		F(i);
		f[id]+=f[i];
//		cout<<id<<' '<<i<<' '<<f[id]<<' '<<f[i]<<'\n';
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		dp[i]=f[i]=-1;
		v[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(x[mid]<=x[i]+d)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		lst[i]=l;
//		cout<<lst[i]<<' ';
		v[l].push_back(i);
	}
//	cout<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(lst[i]==i+1||lst[i]==n)continue;
		for(int j=max((lst[i]-2>=0?lst[lst[i]-2]:0),i)+1;j<=lst[lst[i]-1];j++)
		{
//			cout<<i<<' '<<j<<' ';
			vis[i]=1;
			DP(i);F(j);
			ans+=(dp[i]*f[j]);
		}
//		cout<<ans<<'\n';
	}
//	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		DP(i);F(i);
//		cout<<dp[i]<<' '<<f[i]<<'\n';
	}
	cout<<ans<<'\n';
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t=1;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=2e6+5;
//long long n,d;
//long long x[maxn];
//int lst[maxn];
//int dp[maxn];
//void solve()
//{
//	cin>>n>>d;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>x[i];
//	}
//	for(int i=1;i<=n;i++)
//	{
//		int l=i,r=n;
//		while(l<r)
//		{
//			int mid=l+r+1>>1;
//			if(x[mid]<=x[i]+d)
//			{
//				l=mid;
//			}
//			else
//			{
//				r=mid-1;
//			}
//		}
//		lst[i]=l;
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		queue<int> q;
//		q.push(i);
//		for(int j=i;j<=n;j++)
//		{
//			dp[j]=0;
//		}
//		dp[i]=1;
//		for(int j=i;j<=n;j++)
//		{
//			for(int k=j+1;k<=lst[j];k++)
//			{
//				dp[k]+=dp[j];
//			}
//		}
//		for(int j=i+1;j<=n;j++)
//		{
//			ans+=(dp[j]==2);
//		}
//	}
//	cout<<ans<<'\n';
//}
//int main()
//{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	int c,t=1;
//	cin>>c>>t;
//	while(t--)
//	{
//		solve();
//	}
//}
