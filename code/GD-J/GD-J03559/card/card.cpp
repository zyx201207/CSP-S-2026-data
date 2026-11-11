#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N], c[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i)
		for(int j = 1; j <= n; j++){
			b[j] = 0;
		}
	}
	return 0;
}
