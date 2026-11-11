#include<bits/stdc++.h>
using namespace std;
int T,C;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		long long n,d,ans=0,f[501][501]={0},a[501],num[501][501]={0},ch=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(i==j)f[i][j]=0;
		else f[i][j]=99999999999;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i;j>=1&&a[i]-a[j]<=d;j--){
				f[i][j]=f[j][i]=1;
				num[i][j]=num[j][i]=1;
			}
		}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(f[i][k]+f[k][j]<f[i][j]){
							num[i][j]=num[j][i]=num[i][k]*num[k][j];
							f[i][j]=f[j][i]=f[i][k]+f[k][j];
						}
						else{if(f[i][k]+f[k][j]==f[i][j]){
							num[i][j]=num[i][j]+1;
						}
						}
				}
				}
			}
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					if(num[j][i]==2)ans++;
				}
			}
			cout<<ans<<'\n';
	}
	return 0;
}
