#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	unsigned long long c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		unsigned long long x[n+5],f[n+5][n+5]={0};
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=1;
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				
			}
		}
	}
	return 0;
}
