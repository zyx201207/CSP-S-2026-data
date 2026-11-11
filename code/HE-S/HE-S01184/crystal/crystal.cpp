#include<bits/stdc++.h>

using namespace std;
/*
scanf("%d", &x);
printf("%d", x);
*/
#define ll long long
const int N = 5e5 + 10, V = 210;
int n;
ll m;
ll a[N];
ll b[N];
int ans = 1;
int tot[V + 10];

int erfen(int st, int nd, ll cc, ll zz){
	while(st < nd){
		int mid = st + ((nd - st) >> 1);
		if(cc * (ll)1ll * mid - b[mid] >= zz){
			nd = mid;
		}else{
			st = mid + 1;
		}
	}
	if(cc * (ll)1ll * st - b[st] >= zz) return st;
	return -1;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	if(n <= 5000){
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++){
			ll s = m; int jsq = 1;
			for(int j = i - 1; j >= 1; j--){
				if((s - (a[i] - a[j])) >= 0){
					s -= (a[i] - a[j]);
					jsq++;
				}else{
					break;
				}
			}
			ans = max(ans, jsq);
		}
		printf("%d", ans);
	}else{
		bool oo = true;
		bool o = true;
		sort(a + 1, a + 1 + n);
		ll dc = a[2] - a[1];
		if(abs(a[1]) > 100 || abs(a[2]) > 100){
			o = false;
		}
		for(int i = 3; i <= n; i++){
			if((a[i] - a[i - 1]) != dc) oo = false;
			if(abs(a[i]) > 100) o = false;
		}
		
		if(oo){
			ll s = m; int jsq = 1;
			for(int j = n - 1; j >= 1; j--){
				if((s - (a[n] - a[j])) >= 0){
					s -= (a[n] - a[j]);
					jsq++;
				}else{
					break;
				}
			}
			printf("%d", jsq);
		}else if(o){
			for(int i = 1; i <= n; i++){
				b[i] = a[i] + 101;
				tot[b[i]]++; 
			}
			
			for(int i = 1; i <= V; i++){
				int s = (int)m; int jsq = tot[i];
				for(int j = i - 1; j >= 0; j--){
					if(tot[j] == 0) continue;
					if(s - (tot[j] * (i - j)) >= 0ll){
						s = s - (tot[j] * (i - j));
						jsq = jsq + tot[j];
					}else{
						s = s / (i - j);
						jsq = jsq + (int)s;
						break;
					}
				}
				ans = max(ans, jsq);
			}
			printf("%d", ans);
		}else{
//			sort(a + 1, a + 1 + n);
			for(int i = 1; i <= n; i++){
				b[i] = b[i - 1] + a[i];
			}
			
			for(int i = 1; i <= n; i++){
				ll s = (ll)a[i] * (ll)1ll * ((ll)1ll * i - 1ll) - b[i - 1];
				if(m >= s){
					ans = max(ans, i);
				}else{
					s = s - m;
					int id = erfen(1, i, a[i], s);
//					cout << i << ' ' << id << '\n';
					if(id == -1){
						ans = max(ans, 1);
					}else{
						id++;
						ans = max(ans, i - id + 1);
					}
				}
			}
			printf("%d", ans);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 1
4 6 8 10 12

3 999
1000999 10 1000000
*/
