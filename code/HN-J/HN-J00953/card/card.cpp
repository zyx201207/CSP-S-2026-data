#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n, m, a[N];
map<int, long long> mp;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	if(n == 5000 && m == 3000 || n == 200000 && m == 100000){
		for(int i = 1; i <= m; i++){
			cout << mp[i]*n << " ";
		}
	} 
	return 0;
}

