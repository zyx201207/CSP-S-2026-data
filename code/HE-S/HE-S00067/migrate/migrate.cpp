#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cpo,T,a[2000005],b[2000005],c[2000005];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cpo>>T;
	while(T--)
	{
		ll n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			c[i]=0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=0;
				c[i]=0x3f3f3f3f;
			}
			queue<ll> mp,ft;
			mp.push(i);
			ft.push(0);
			while(!mp.empty())
			{   
				ll p=mp.front(),tt=ft.front();
				//cout<<p<<" "<<tt<<endl;
				mp.pop();
				ft.pop();
				if(tt<c[p])
				{
					c[p]=tt;
					b[p]=1;
				}
				else if(tt==c[p])
				{
					b[p]++;
				}
				for(int i=1;i<=n-p;i++)
				{
					if(d<a[p+i]-a[p]) break;
					mp.push(p+i);
					ft.push(tt+1);
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(b[i]==2) ans++;
				//cout<<b[i]<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
