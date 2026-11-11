#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5 + 10;
int n, m;
long long a[N], v[N];
bool used[N];
long long ddy(long long n, long long m){
	string s;
	long long j = 1, k = 0, l = 0;
	long long maxx = max(n, m);
	while(maxx){
		int x = n % 2;
		n /= 2;
		int y = m % 2;
		m /= 2;
		if((bool)x && (bool)y){
			s[l] = '1';
		} else {
			s[l] = '0';
		}
		maxx /= 2;
		l++;
	}
	for(int i = 0; i < l; i++){
		k += (s[i] - '0') * j;
		j *= 2;
	}
	return k;
}
void dfs(int s, long long maxx){
	if(s == m){
		long long x;
		for(int i = 1; i <= s; i++){
			if(i == 1){
				x = v[1];
			} else {
				x = ddy(x, v[i]);
			}
		}
		maxx = max(maxx, x);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!used[i] && a[i] >= v[s]){
			v[s++] = a[i];
			used[i] = true;
			dfs(s, maxx);
			used[i] = false;
		}
	}
}
int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long maxx = LLONG_MIN;
//	dfs(0, maxx);
//	cout << maxx;
for(int i = 1; i < n ; i++){
	for(int j = i; j <= n; j++){
		maxx = max(maxx, ddy(a[i] ,a[j]) );
	}
}
    cout << maxx;
	return 0;
}
