#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int c,t,n;
ll d,a[2000010],f[1010][1010],g[1010][1010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					f[i][j]=1;
					g[i][j]=1;
				}
				else{
					f[i][j]=1e9;
					g[i][j]=1e9;
				}
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						g[i][j]=1;
						//cout<<i<<" "<<k<<" "<<j<<" "<<g[i][j]<<endl;
					}
					else if(f[i][k]+f[k][j]==f[i][j]){
						g[i][j]+=g[i][k]*g[k][j];
						//cout<<i<<" "<<k<<" "<<j<<" "<<g[i][j]<<endl;
					}
				}
				if(g[i][j]==2){
					ans++;
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}*/
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
