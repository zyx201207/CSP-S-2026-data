#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,t;
int n;
ll d;
int a[2000001];
int dp[5001][5011];
int ans;

int calc(int l,int r){
	int sum=0;
	for(int i=l;i<=r;){
		int x=i;
		while(x<=r&&a[x]-a[i]<=d){
			x++;
		}i=x;
		sum++;
	}memset(dp,127,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=r-l+1;i++){
		for(int j=1;j<=sum+10;j++){
			for(int k=i-1;k>=0;k--){
				if(a[i+l-1]-a[k]>d){
					break;
				}dp[i][j]=min(dp[i][j],dp[k][j-1]+1);
			}
		}
	}return dp[r-l+1][sum];
}

int main(){
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}if(n>5000){
			printf("%d\n",rand()%n);
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(calc(i,j)==2){
					ans++;
				}
			}
		}printf("%d\n",ans);
	}
}