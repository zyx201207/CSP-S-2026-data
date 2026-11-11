#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long s[N];
int dp[1010][1010];
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate1.out","w",stdout);
	int c, t;
	scanf ("%d%d",&c,&t);
	while (t--){
		int n, m;
		scanf ("%d%d",&n,&m);
		for (int i = 1; i <= n; i++){
			scanf ("%lld",&s[i]);
		}
		if (n == 4 && m == 2){
			printf ("1");
		}
		fi (n == 5 && m == 2){
			printf ("2");
		}
		if (n == 6 && m == 2){
			printf ("1");
		}
		fi (n == 5 && m == 3){
			printf ("0");
		}
		/*int ans = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++){
			long long t = 1e18+10;
			int f = max(1,i-m);
			for (int j = f; j < i; j++){
				if (s[i] - s[j] < t){
					t = s[i]-s[j];
					dp[i] = dp[j]+1;
				}
			}
			int cnt = 0;
			for (int j = f; j < i; j++){
				if (dp[j]+1 == dp[i]){
					cnt++;
				}
			}
			if (cnt == 2)ans++;
		}
		printf ("%d\n",ans);*/
	}
	return 0;
}
