#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],dp[N],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++){
		maxx=max(maxx,a[i-1]);
		dp[1]=maxx;
		for(int j=m;j>=2;j--){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}
