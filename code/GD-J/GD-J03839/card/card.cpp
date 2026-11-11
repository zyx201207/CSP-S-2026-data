#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],dp[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d" ,&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&a[i]);
		b[a[i]] = i;
		dp[i] = 1;
	}
	for(int i = 1;i <= n;i++){
		if(b[a[i]] == i){
			ans[a[i]] = dp[i];
			dp[i + 1] += dp[i];
		}else{
			dp[b[a[i]]] += dp[i];
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d " ,ans[i]);
	}
	return 0;
}
