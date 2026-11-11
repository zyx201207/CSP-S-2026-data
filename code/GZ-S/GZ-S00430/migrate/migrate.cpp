//GZ-S00430,贵阳市第一中学，陶昱泽
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d; 
long long dy[5005];
int dp1[5005];
int dp2[5005];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	dp1[0]=1e9;
	if(c<=10){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>dy[i];	
				dp1[i]=n+1;
			}
			for(int i=1;i<=n;i++){
				dp1[i]=0;
				dp2[i]=1;
				for(int j=i+1;j<=n;j++){
					dp1[j]=n+1;
					dp2[j]=0;
				}
				for(int j=i;j<=n;j++){
					for(int k=j-1;k>=i;k--){
						if(dy[j]-dy[k]<=d){
							if(dy[j]-dy[k-1]>d&&dp2[k-1]>2){
								j+=n;
							}
							if(dp1[k]+1<dp1[j]){
								dp2[j]=dp2[k];
								dp1[j]=dp1[k]+1;
							}else if(dp1[k]+1==dp1[j]){
								dp2[j]+=dp2[k];
							}else{
								break;
							}
						}
					}
				if(dp2[j]==2){
					ans++;
				}
				}

			}
			cout<<ans;
			cout<<endl;
		}
	}
	return 0;
}  

