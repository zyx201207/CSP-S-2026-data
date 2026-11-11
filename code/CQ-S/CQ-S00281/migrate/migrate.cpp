#include<bits/stdc++.h>
#define ll long long
//#define int ll//#
#define db double
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fr front
#define bk back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
const int mod=1e9+7;
int n,to[2000005];
ll d,x[2000005];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)to[i]=i;
	int j=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		while(j<i&&x[i]-x[j]>d)
		{
			to[j]=i-1;
			j++;
		}
	}
	for(int i=j;i<=n;i++)to[i]=n;
//	for(int i=1;i<=n;i++)cerr<<to[i]<<"\n";
//	cerr<<"\n";
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=i,a,b,c;
		int num=0;
		if(to[u]==i)continue;
		while(1)
		{
			a=to[u],b=to[u]-1,c=to[u]-2;
			if(b<=u)
			{
				if(to[a]-to[b]<1)break;
				u=a;
				continue;
			}
			num+=to[b]-to[c];
			ans+=to[b]-to[c];
			u=a;
			if(to[a]==to[b])
			if(to[a]-to[b]<1||a>=n)break;
		}
//		cerr<<i<<" "<<num<<"*\n";
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

