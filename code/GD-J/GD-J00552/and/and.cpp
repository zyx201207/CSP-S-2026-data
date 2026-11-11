#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 7;
long long f[MAXN], a[MAXN];
int n, m;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.ans", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(j - 1 == 0){
				f[j] = max(f[j], a[i]);
			}
			else{
				f[j] = max(f[j], f[j - 1] & a[i]);
			}
		}
	}
	cout << f[m];
	return 0;
} 
