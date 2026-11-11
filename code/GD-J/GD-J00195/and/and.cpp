#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
ll a[N];
bool b[N][35];
ll ma,maxx;
ll ans[31];
ll vis[N];
ll p;
ll e[N];
ll da;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	e[1]=1;
	for(int i=2;i<=31;i++)e[i]=e[i-1]*2;
	//for(int i=1;i<=31;i++)cout<<e[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ll ds=a[i],cnt=0;
		while(ds>0)
		{
			ll g=ds%2;
			b[i][++cnt]=g;
			ds/=2;
		}
		ma=max(ma,cnt);
	}
	//cout<<maxx<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ma;j++)
		{
			ans[j]+=b[i][j];
		}
	}
	for(int i=ma;i>=1;i--)
	{
		if(ans[i]>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j][i]==1)vis[j]=1;
				//cout<<j<<":"<<b[j][i]<<" ";
			}
			p=i;
			break;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)cout<<i<<" ";
	}*/
	for(int i=p;i>=1;i--)
	{
		ll sum=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1)sum+=b[j][i];
		}
		if(sum>=m)
		{
			//da+=e[i];
			//cout<<sum<<" ";
			for(int j=1;j<=n;j++)
			{
				if(b[j][i]==0)vis[j]=0;
			}
		}
	}
	//for(int i=1;i<=n;i++)if(vis[i]==1)cout<<a[i]<<" ";
	for(int i=p;i>=1;i--)
	{
		ll sum=0,cnt1=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1)sum+=b[j][i],cnt1++;
		}
		if(sum==cnt1)
		{
			da+=e[i];
		}
	}
	cout<<da;
	return 0;
}

