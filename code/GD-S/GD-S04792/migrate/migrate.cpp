#include <iostream>
#include <fstream>
#define ll long long
using namespace std;
struct p{
	ll x,v;
} a[2000005];
ll c,t,n,d,w[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1; i<=n; i++)cin>>w[i];
		for(int l=1; l<=n; l++)
			for(int r=l+1; r<=n; r++){
				for(int i=0; i<=n; i++)a[i].x=0,a[i].v=999999;
				a[l].x=1,a[l].v=0;
				for(int i=l; i<=r; i++)
				for(int j=i+1; j<=r; j++)
					if(w[j]<=w[i]+d){
						if(a[j].v > a[i].v+1)
							a[j].v = a[i].v+1 , a[j].x = 1;
						else if(a[j].v == a[i].v+1)
							a[j].x += a[i].x;
					}else break;
				ans += (a[r].x==2);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
