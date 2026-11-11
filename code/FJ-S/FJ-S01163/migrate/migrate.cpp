//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 2e6+10,INF = 0x3f3f3f3f;
//int C,T; 
//int n;
//ll d;
//ll ans;
//ll a[N];
//int MAX[N];
//ll dp[N][3];
//void solve(){
//	ans = 0;
//	scanf("%d%lld",&n,&d);
//	for(int i = 1;i<=n;i++)scanf("%lld",a+i);
//	for(int i = 1;i<=n+1;i++)MAX[i] = 0;
//	for(int i = 1,j = 1;i<=n;i++){
//		dp[i][0] = dp[i][1] = dp[i][2] = 0;
//		while(a[i]-a[j] > d){
//			MAX[j] = i-1;
//			printf("%d ",MAX[j]); 
//			j++;
//		} 
//		if(i == n)while(j <= n)MAX[j] = n,j++;
//	}
//	puts("");
//	for(int i = 1;i<=n;i++){
//		printf("%lld %lld %lld %lld\n",dp[i][0],dp[i][1],dp[i][2],ans);
//		ans += dp[i][2];
//		if(MAX[i] == i)continue;
//		if(MAX[i] == MAX[i+1])dp[MAX[i]][2] += dp[i][1]*(MAX[i]-MAX[i-1]); 
//		else if(i!=n)ans += dp[i][1]*(MAX[i]-MAX[i-1]);
//		if(MAX[i] == i+1 ||MAX[MAX[i]]>MAX[MAX[i]-1]){
////			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
//			if(MAX[i]!=i+1)dp[MAX[i]-1][1] += dp[i][0]+1;
//			dp[MAX[i]][0] += dp[i][0]+1;
//			dp[MAX[i]][2] += dp[i][2];
//		}else if(MAX[i] == i+2 || MAX[MAX[i]] > MAX[MAX[i]-2]){
////			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
//			dp[MAX[i]-1][1] += dp[i][0]+1;
//			
//		}else{
////			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
//		}
//		
//	}
//	printf("%lld\n",ans);
//}
//int main(){
////	freopen("migrate3.in","r",stdin);
////	freopen("migrate.out","w",stdout);
//	scanf("%d%d",&C,&T);
//	while(T--){
//		solve();
//	} 
//	
//	return 0;
//}/*
//0 2
//5 2
//1 2 3 4 5
//
//0 1
//10 272727272727272724
//-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
//
//0 1
//10 2
//0 2 4 6 7 8 9 11 13 14 
//
//
//2 3 4 6 7 7 8 9
//
//
//0 1
//7 2
//0 2 3 4 5 5 7
//
//0 1
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
//*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+10,INF = 0x3f3f3f3f;
int C,T; 
int n;
ll d;
ll ans;
ll a[N];
int MAX[N];
ll dp[N][2];

void work(){
	for(int i = 1,j = 1;i<=n;i++){
		dp[i][0] = dp[i][1] = 0;
		while(a[i]-a[j] > d){
			MAX[j] = i-1; 
			j++;
		} 
		if(i == n)while(j <= n)MAX[j] = n,j++;
	}
	for(int i = 1;i<=n;i++){
		 if(MAX[i] == i+1 ||MAX[MAX[i]]>MAX[MAX[i]-1]){
			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
			if(MAX[i]!=i+1)dp[MAX[i]-1][1] += dp[i][0]+1;
			dp[MAX[i]][0] += dp[i][0]+1;
		}else if(MAX[i] == i+2 || MAX[MAX[i]] > MAX[MAX[i]-2]){
			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
			dp[MAX[i]-1][1] += dp[i][0]+1;
		}else{
			ans += dp[i][1]*(MAX[i] - MAX[i-1]);
		}
	} 
	printf("%lld\n",ans); 
}
void solve(){
	ans = 0;
	scanf("%d%lld",&n,&d);
	for(int i = 1;i<=n;i++)scanf("%lld",a+i);
	if(n > 5000){
		work();
		return;
	} 
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j <=n;j++){
			dp[j][0] = INF;
			dp[j][1] = 0;
		}
		dp[i][0] = 0;
		dp[i][1] = 1;
		for(int j = i+1;j <= n;j++){
		 	for(int k = j-1;k >= i;k--){
		 		if(a[j]-a[k] > d)break;
		 		if(dp[j][0] > dp[k][0]+1){
		 			dp[j][0] = dp[k][0]+1;
		 			dp[j][1] = dp[k][1];
				}else if(dp[j][0] == dp[k][0]+1){
					dp[j][1] += dp[k][1];
				}
			}
			if(dp[j][1] == 2){
//				printf("%d %d\n",i,j);
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		solve();
	} 
	
	return 0;
}/*
0 2
5 2
1 2 3 4

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

0 1
10 2
0 2 4 6 7 8 9 11 13 14 


2 3 4 6 7 7 8 9
*/
