#include<bits/stdc++.h>
#define int long long
#define MAXN 5005
using namespace std;
int cc,T,n,d,a[MAXN],f[MAXN][MAXN],c[MAXN][MAXN],ta[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&cc,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		if(n==1){
			for(int i=1;i<=n;i++)scanf("%lld",&ta[i]);
			printf("0\n");
			continue;
		}
		if(cc==11||cc==12){
			for(int i=1;i<=n;i++)scanf("%lld",&ta[i]);
			int tmp=ta[2]-ta[1],ans=0;
			tmp=d/tmp;
			if(tmp<2){
				printf("0\n");
				continue;
			}
			//cout<<tmp<<"!!!\n";
			tmp=tmp*2+1;
			ans=max(0ll,n-tmp+2);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[i][j]=INT_MAX,c[i][j]=0;
		}
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)f[i][j]=1,c[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						c[i][j]=c[i][k]*c[k][j];
					}else if(f[i][k]+f[k][j]==f[i][j]){
						c[i][j]+=c[i][k]*c[k][j];
					}
				}
				//cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<c[i][j]<<"\n";
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c[i][j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

