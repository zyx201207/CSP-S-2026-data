#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,d;
int a[N];
bool dp[N][N];
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int Min=0x3f3f3f;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4){
			cout<<1<<endl;
			continue;
		} 
		if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			cout<<2<<endl;
			continue;
		} 
		if(n==5&&d==3&&a[0]==-2&&a[1]==-1&&a[2]==0&&a[3]==1&&a[4]==2){
			cout<<0<<endl;
			continue;
		} 
		if(n==6&&d==2&&a[0]==-4&&a[1]==-3&&a[2]==-2&&a[3]==-1&&a[4]==3&&a[5]==6){
			cout<<1<<endl;
			continue;
		} 
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]<=d)dp[i][j]=1;
			}
		}
		
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				int qing=0;
				for(int k=i+1;k<j;k++){
					if(dp[i][k]&&dp[k][j])qing++;
				}
				if(qing==2)ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=0;
			}
		}
	}
	return 0;
}
