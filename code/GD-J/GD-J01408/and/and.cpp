#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long dp[2][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[1][i]=a[i];
	}
	if(m==1){
		long long maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		printf("%lld",maxn);
        return 0;	
	}else if(m==n){
	    long long ans=a[1];
	    for(int i=1;i<=n;i++) ans=ans&a[i];
		printf("%lld",ans);
		return 0; 
	} 
	int pos=0;
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			if(j==i){
				dp[pos][j]=dp[!pos][j-1]&a[j];
			}else{
				dp[pos][j]=max(dp[!pos][j],dp[!pos][j-1]&a[j]);
			}
		}
		pos=!pos;
	}
	cout<<dp[!pos][n];
	return 0;
}
