#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 5e5 + 10;
int n, m, a[N], ans[N];
bool bk[N];

void did(int st, int ed){
	for(int i = st; i <= ed; i++){
		bk[a[i]] = true;
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], ans[a[i]]++;
	ans[a[n]] = n;
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
} 
