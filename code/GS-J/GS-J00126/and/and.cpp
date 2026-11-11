#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[200100];
int a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		dp[m] = a[i];
		for(int j = m;j >= 1;j--){	
			dp[j] = max(dp[j],a[i] & dp[j - 1]);
		}
	}
	printf("%d",dp[m]);
}
