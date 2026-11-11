#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b){
	int sum1 = 0, k1 = 0, aa = a;
	while(aa){
		if(aa % 2 == 1) sum1++;
		aa /= 2; 
		
	}
	int sum2 = 0, k2 = 0, bb = b;
	while(bb){
		if(bb % 2 == 1) sum2++;
		bb /= 2;
	}
	if(sum1 != sum2) return sum1 > sum2;
	return a > b;
}

int main(){
	//freopen("and4.in", "r", stdin);
	//freopen("and4.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	long long a[200005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	
	long long maxn = -1;
	for(long long i = 1; i <= n - m; i++){
		long long c = pow(2, 31) - 1;
		for(int j = i; j <= i + m - 1; j++){
			c &= a[j];
		}
		maxn = max(maxn, c);
	}
	cout << maxn;
	
	return 0;
}
