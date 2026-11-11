#include<bits/stdc++.h>
using namespace std;
const long long N = 5 * 100000 + 5;
long long n, m;
long long a[N], b[N], p[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		bool sta[N] = {0};
		for(long long k = i; k <= n; k++){
			long long x = a[k];
			if(sta[x]){
				for(long long j = k; j >= p[x]; j--){
					sta[a[j]] = 0;
				} 
			}
			sta[x] = 1;
			p[x] = i;
		}
		for(long long j = 1; j <= m; j++){
			if(sta[j]) {
				b[j]++;
			}
		}
	}
	for(long long i = 1; i <= m; i++) cout << b[i] << " ";
	return 0;
}
