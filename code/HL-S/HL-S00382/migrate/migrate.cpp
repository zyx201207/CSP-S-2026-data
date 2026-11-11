#include<iostream>
#include<cmath>
using namespace std;

long long c,t,n,d,x[50005],f[50005][50005],sum=0;
void floid(){
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j]; 
				}else if(f[i][j]==f[i][k]+f[k][j]&&j!=i){
					sum++;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<d){
					f[i][j]=1;
				}
			}
		}
		floid();
		
		cout<<sum;
	}
	return 0; 
}
