#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,n,ans;
ll d,a[N],dis[500][500];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		memset(dis,0,sizeof(dis));
		for(register int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=5000){
			for(register int i=1;i<=n;i++){
				for(register int j=i+2;j<=n;j++){
					for(register int k=i+1;k<j;k++){
						if((a[k]-a[i]+d-1)/d+(a[j]-a[k]+d-1)/d==(a[j]-a[i]+d-1)/d) dis[i][j]++;
					}
				}	
			}
			for(register int i=1;i<=n;i++){
				for(register int j=i+1;j<=n;j++){
					if(dis[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
