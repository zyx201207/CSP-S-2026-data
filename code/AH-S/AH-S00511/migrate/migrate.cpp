#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x)
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int c,t;
int n,d;
int a[2000005];
int dis[5005][5005];
int sum[5005][5005];
bool sub_1_10(){
	return n<=1000000;
}
int dp[5005][5005];
int dfs(int u,int s,int l,int r){
	if(dp[u][s]!=-1) return dp[u][s];
	if(u==r){
		dp[u][s]=(s==dis[l][r]);
		return s==dis[l][r];
	}
	int sum=0;
	for(int i=u+1;i<=r;i++){
		if(a[i]-a[u]<=d){
			sum+=dfs(i,s+1,l,r);
			if(sum>2) {
				sum=INF;
				break;
			}
		}else break;
	}
	dp[u][s]=sum;
	return sum;
}
void solve_1_10(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int cnt=0,sum=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) break;
			if(sum+a[j]-a[j-1]>d){
				sum=0;
				cnt++;
			}
			sum+=a[j]-a[j-1];
			
			dis[i][j]=cnt+1;
		}
	}
	int s=0;
	for(int k=0;k<=n;k++){
		for(int l=0;l<=n;l++){
			dp[k][l]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]==INF) break;
			//debug("%d %d\n",i,j);
			if(dfs(i,0,i,j)==2){
				s++;
			}
			for(int k=0;k<=n;k++){
				for(int l=0;l<=n;l++){
					dp[k][l]=-1;
				}
			}
		}
	}
	cout<<s<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(sub_1_10()){
			solve_1_10();
			continue;
		}
	}
	return 0;
}
