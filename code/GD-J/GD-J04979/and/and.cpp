#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;

int n, m, num[N], ans = 0, b[N];
bool a[N][35], v[N];

bool cmp(int a, int b){
	return a > b;
}

void two(int t){
	for(int i = 30; i >= 0; i--){
		if(num[t] == 0) return ;
		if(num[t] < pow(2, i)) continue;
		a[t][i] = 1;
		num[t] -= (int)(pow(2, i));
	}
	return ;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
	}
	sort(num + 1, num + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		two(i);
	}
	int t = n, count = 0, p;
	for(int i = 30; i >= 0; i--){
		if(t - count == m) break;
		p = count;
		for(int j = 1; j <= t; j++){
			if(v[j]) continue;
			if(!a[j][i]){
				if(t - count > m){
					t = j - 1;
					break;
				}else b[++count] = j;
			}
		}
		for(int j = p + 1; j <= count; j++){
			v[b[j]] = 1;
		}
	}
	for(int i = 30; i >= 0; i--){
		bool c = 1;
		for(int j = 1; j <= m + count; j++){
			if(v[j]) continue;
			if(!a[j][i]){
				c = 0;
				break;
			}
		}
		ans += c * (int)(pow(2, i));
	}
	printf("%d", ans);
	return 0;
} 
