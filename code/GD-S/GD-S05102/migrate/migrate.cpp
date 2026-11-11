#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define ldb long double
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)

const int N=2e6;

int n;
ll d;
ll a[N+5];
int b[N+5];
int c[N+5];

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int r=1;
	for(int i = 1;i<=n;i++)
	{
		c[i]=0;
		while(r+1<=n&&a[r+1]-a[i]<=d)r++;
		b[i]=r;
	}
	ll ans=0;
	for(int i = 1;i<=n;i++)
	{
		c[i]=1;
		int now=i;
		int l=i;
		for(int j = i+1;j<=n;j++)
		{
			c[j]=0;
			while(b[now]<j)
			{
				if(b[now]==now)break;
				now=b[now];
			}
			if(b[now]==now)break;
			while(l<=n&&a[l]+d<a[j])l++;
			if(now-l>1)c[j]=3;
			else if(now==l)c[j]=c[now];
			else
			{
				if(c[now]==1&&c[l]==1)c[j]=2;
				else c[j]=3;
			}
			if(c[j]==2)ans++;
//			cout<<i<<' '<<l<<' '<<now<<' '<<j<<' '<<c[j]<<' '<<ans<<endl;
		}
//		cout<<endl;
//		for(int j = i;j<=n;j++)cout<<c[i]<<' ';
//		cout<<endl;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t=1;
	cin>>c>>t;
	while(t--){solve();}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

