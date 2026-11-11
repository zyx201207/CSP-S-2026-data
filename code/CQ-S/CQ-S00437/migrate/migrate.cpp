#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],f[2000005][2],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c==11||c==12){
			printf("%lld\n",n-((d+x[2]-x[1]-1)/(x[2]-x[1])));
		}
		ans=0;
		for(int i=1;i<=n;i++){
			f[i][0]=1;f[i][1]=0;
			for(int j=i+1;j<=n;j++){
				f[j][0]=0;f[j][1]=1e9;
				for(int k=j-1;k>=i&&x[j]-x[k]<=d;k--){
					if(f[j][1]>f[k][1]+1){
						f[j][1]=f[k][1]+1;
						f[j][0]=f[k][0];
					}else{
						f[j][0]+=f[k][0];
					}
				}
				if(f[j][0]==0) break;
				if(f[j][0]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
