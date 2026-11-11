#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
long long f, ans;
struct E{
	long long a, c;
} e[N];

int cmp(E x, E y){
	return x.c < y.c;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> e[i].a;
		int cnt = 0;
		ans = e[i].a;
		while(ans){
		 	if(ans % 2){
		 		cnt++;
			}
			ans /= 2;
		}
		e[i].c = cnt;
	}
	f = e[n].a;
	sort(e+1, e+n+1, cmp);
	for(int i = n-1; i > n-m; i--){
		f &= e[i].a;
	}
	cout << f;
	return 0;
}

