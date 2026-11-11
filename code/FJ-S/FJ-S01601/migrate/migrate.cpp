#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sl=0,ans=0;
long long zb[2000050],dp[5000];
long long lj[5000][5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>zb[j];
			
		}
		for(int j=1;j<n;j++){
			for(int z=j+1;z<=n;z++){
				if(max(zb[j],zb[z])-min(zb[j],zb[z])<=d){
					lj[j][z]=1;
				}else{
					lj[j][z]=0;
				}
		}
		}
		for(int j=1;j<n;j++){
			for(int z=j+1;z<=n;z++){
				sl=0;
				for(int q=j+1;q<z;q++){
					if(lj[j][q]==1&&lj[q][z]==1&&lj[j][z]==0){
						sl++;
					}
		}
		if(sl==2){
			ans++;
		}
		}
		}
		cout<<ans<<endl;	
	} 
 
	return 0;
}
