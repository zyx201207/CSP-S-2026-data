#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000005],ans,a,b,vis[2000005],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}
		ans=0;
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = 1;k <= n;k++){
					if(i<=k&&k<=j)vis[k]=0;
					else vis[k]=1;
				}
				a=i;
				b=j;
				cnt=1;
				while(a!=b){
					for(int k = b;k >= a;k--){
						if(k==a){
							cnt=0;
							a=b;
							break;
						}
						if(x[k]-x[a]==d){
							vis[a]=1;
							a=k;
							break;
						}
						if(x[k]-x[a]<d){
							ll cc=0;
							for(int l = a;l >= 1;l--){
								if(x[k]-x[l]<=d){
									if(vis[l]==0){
										cc++;
										vis[l]=1;
									}
								}else{
									break;
								}
							}
							cnt*=cc;
							a=k;
							break;
						}
					}
					if(cnt>2)break;
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
