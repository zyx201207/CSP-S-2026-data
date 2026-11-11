#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll c,T;
ll n,m;
ll a[N],b[N];
ll s[N];
ll p[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			b[i]=a[i+1]-a[i];
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll flag=0;
			for(int j=i+1;j<=n;j++)
			{
				ll cnt=1;
				s[1]=0;
				for(int k=i;k<j;k++)
				{
					s[cnt]+=b[k];
					if(b[k]>m)
					{
						flag=1;
						break;
					}
					if(s[cnt]>m)
					{
						s[cnt]-=b[k];
						p[cnt]=k-1;
						cnt++;
						s[cnt]=b[k];
					}
				}
				if(flag==1)break;
				ll kkkw=0;
				for(int k=2;k<=cnt;k++)
				{
					if(s[k]+b[p[k-1]]<=m)kkkw++;
					if(s[k]+b[p[k-1]]+b[p[k-1]-1]<=m)kkkw++;
				}
				if(kkkw==1)ans++;
				/*for(int k=2;k<cnt;k++)
				{
					cout<<s[k]<<" ";
				}*/
				//cout<<kkkw<<" ";
				//cout<<"\n";
			}
			//cout<<"here is dividing line...\n";
			//cout<<"\n";
		}
		//cout<<"here is dividing line...\n";
		cout<<ans<<"\n";
	}

	return 0;
}

