#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000;
long long ave; 
long long cs[MAXN+5];
bool cmp(long long a, long long b){
	if(abs(ave - a) != abs(ave - b)) return abs(ave - a) < abs(ave - b);
	else return a > b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> cs[i];
		ave += cs[i];
	}
	ave = ave * 1.0 / n;
	sort(cs+1, cs+n+1, cmp);
	long long ans = 1;
	for(int i = 2; i <= n; i++){
		if(cs[i] > cs[1] || m < cs[1] - cs[i]){
			continue;
		} 
		m -= cs[1] - cs[i];
		ans++;
	}
	cout << ans;
	return 0;
}
