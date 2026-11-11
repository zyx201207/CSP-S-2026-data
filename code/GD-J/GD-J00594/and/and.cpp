#include<bits/stdc++.h>
using namespace std;
int n, m, crr[200010];
long long arr[200010], ans, o = 1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
	}
	for(int i=30; i>=0; i--){
		int c = 0;
		for(int j=1; j<=n; j++){
			if(crr[j] == 0 && (arr[j] & (o << i))){
				c++;
			}
		}
		if(c >= m){
			ans += (o << i);
			for(int j=1; j<=n; j++){
				if((arr[j] & (o << i)) == 0){
					crr[j] = 1;
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
