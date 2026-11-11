#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,t,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(1)//(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			if(n==1||n==2)
			{
				cout<<"0\n";
				continue;
			}
			ll det=x[2]-x[1];
			if(det*2>d)
			{
				cout<<"0\n";
				continue;
			}
			cout<<(n-1)*(n-2)/2<<'\n';
		}
		return 0;
	}
	/*while(t--)
	{
		cin>>n>>d;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				ll dis=x[i]-x[j];
				if(dis<=d)
				{
					cnt[i][j]+=;
				}
			}
		}
	}*/
	return 0;
}
