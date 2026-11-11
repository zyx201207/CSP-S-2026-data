#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long zb[3000000],dis2[6000][6000],ans=0,tim[6000][6000];
void fly(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis2[i][j]=min(dis2[i][k]+dis2[k][j],dis2[i][j]);
			}
		}
	}
}
void fly2(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis2[i][j]==dis2[i][k]+dis2[k][j]&&dis2[i][j]<1e8)tim[i][j]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(zb,0,sizeof(zb));
		memset(tim,0,sizeof(tim));
		ans=0;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>zb[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j>i&&zb[j]-zb[i]<=d){
					dis2[i][j]=1;
				}
				else{
					dis2[i][j]=1e8;
				}
			}
		}
		fly();
		fly2();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//cout<<dis2[i][j]<<" ";
				if(tim[i][j]==2)ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
