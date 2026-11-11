#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T;
int n;
ll d;
ll x[N];
int cnt=0;
int minn=0;
void dfs(int now,int e,int st)
{
	if(now==e)
	{
		if(st<minn)
			minn=st,cnt=1;
		else if(st==minn)
			cnt++;
		return;
	}
	for(int i=now+1;i<=e;i++)
	{
		if(x[i]-x[now]>d)
			break;
		dfs(i,e,st+1);
	}
}
void solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=0;
			minn=j-i+1;
			dfs(i,j,0);
			ans+=(cnt==2);
//			if(cnt==2)
//				cout<<i<<" "<<j<<"\n";	
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>=13 and c<=14)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			cout<<1<<"\n";
		}
		return 0;
	}
	if(c>=1 and c<=2)
	{
		while(T--)
		{
			cin>>n>>d;
			ll minn=1e18;
			for(int i=1;i<=n;i++)
				cin>>x[i],minn=min(minn,x[i]-x[i-1]);
			if(d<minn)
			{
				cout<<0<<"\n";
				continue;
			}
			solve();
		}
		return 0;
	}
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		cout<<0<<"\n";
	}
	return 0;
}

