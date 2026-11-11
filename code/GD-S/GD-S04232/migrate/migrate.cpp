#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,_,dist[N],a[N],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
	memset(dist,0,sizeof(dist));
	scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}dist[1]=1;ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])<=d){
					dist[j]+=dist[i];
				}else break;
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d){
			ll need=dist[j];
				for(int z=i-1;z>=1;z--){
					if((a[i]-a[z])<=d){
						need-=dist[z];
					}else break;
				}if(need==2){
				ans++;	cout<<i<<" "<<j<<"\n";
				}
			}	
			}
		}printf("%lld\n",ans); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
