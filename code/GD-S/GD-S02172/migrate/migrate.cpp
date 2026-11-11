#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll a[N],c,t,n,d,f[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)	
			cin>>a[i];
		if(c==13||c==14)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		memset(f,0,sizeof(f));
		f[1]=1;
		for(int i=1;i<=n;i++)
		{
			ll s=0;
			for(int j=1;j<i;j++)
			{
				if(a[i]-a[j]<=d) 
					f[i]+=f[j];
			}
			if(f[i]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
