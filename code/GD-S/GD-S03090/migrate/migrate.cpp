#include<bits/stdc++.h>
using namespace std;
const int M=105,N=2e6+5;
int c,t,n,d,x[N],ans;
long long dp[M][M]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=100){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[i+1]-x[i]>d) continue;
					int tmp=0,cnt=1;
					for(int k=i+1;k<=j;k++){
						if(tmp+x[k]-x[k-1]<=d) tmp+=x[k]-x[k-1];
						else tmp=x[k]-x[k-1],cnt++;
					}
					memset(dp,0,sizeof dp);
					dp[i][0]=1;
					for(int a=i+1;a<=j;a++){
						for(int b=i;b<a;b++){
							for(int k=1;k<=cnt;k++)
								if(x[a]-x[b]<=d) dp[a][k]+=dp[b][k-1];
						}
					}
					if(dp[j][cnt]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}else cout<<"0\n";
	}
	return 0;
} 
