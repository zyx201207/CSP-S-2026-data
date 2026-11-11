#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310;
int c,t;
int n;
ll x[N],d;
int dis[N],dp[N],ans;
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		//init();
		scanf("%d%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int p=1;p<=n;p++){
			dp[p]=1;//cout<<p<<':'<<endl;
			for(int i=p;i<=n;i++){
				
				for(int j=i+1;x[j]-x[i]<=d && j<=n;j++){
					if(dis[i]+1<dis[j] ||dis[j]==0){
						dis[j]=dis[i]+1;
						dp[j]=dp[i];
					}
					else if(dis[i]+1==dis[j]){
						dp[j]+=dp[i];
					}
					//cout<<i<<' '<<j<<' '<<dis[j]<<' '<<dp[j]<<endl;
				}
				
			}for(int i=p;i<=n;i++)if(dp[i]==2)ans++;
				for(int i=p;i<=n;i++)dis[i]=dp[i]=0;
		}
		printf("%d\n",ans);
		
	}
	return 0;
}