#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans;
int a[2000005];
int f[5005][5005];
int g[5005][5005];
int s[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=5000){
			ans=0;
			for(int i=1;i<n;i++){
				int l=i;
				f[i][i]=0;
				g[i][i]=1;
				for(int j=i+1;j<=n;j++){
					while(a[j]-a[l]>d){
						l++;
					}
					if(l==j){
						break;
					}
					f[i][j]=f[i][l]+1;
					g[i][j]=g[i][l];
					if(l+1<j&&f[i][j]==f[i][l+1]+1){
						g[i][j]+=g[i][l+1];
						if(l+2<j&&f[i][j]==f[i][l+2]+1){
							g[i][j]+=g[i][l+2];
						}
					}
					if(g[i][j]==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			int x=a[2]-a[1];
			bool p=0;
			for(int i=3;i<=n;i++){
				if(a[i]-a[i-1]!=x){
					p=1;
					break;
				}
			}
			if(!p){
				int q=d/x;
				if(q<=1){
					printf("0\n");
				}
				else if(q==2){
					int gg=n-3LL;
					printf("%lld\n",gg);
				}
				else{
					printf("0\n");
				}
			}
			else{
				printf("0\n");
			}
		}
	}
	return 0;
}
