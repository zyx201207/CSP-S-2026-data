#include<bits/stdc++.h>
using namespace std;
int n,d,c,t,m,b[2000001],a[5009][5009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		m=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=999999999;
			}
		}
		for(int i=1;i<=n;i++){
			a[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i][j]==a[i][k]+a[k][j]&&abs(b[i]-b[k])<=d&&abs(b[j]-b[k])<=d){
						if(a[i][j]==999999999){
							a[i][j]=1;
							a[j][i]=1;
						}else{
							a[i][j]++;
							a[j][i]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i][k]==a[j][k]&&a[i][k]!=999999999)m++;
				}
			}
		}
		cout<<m<<endl; 
	}
	return 0;
} 
