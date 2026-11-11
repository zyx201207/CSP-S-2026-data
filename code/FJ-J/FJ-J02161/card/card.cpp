#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long a[N], st[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n , m;
	cin >> n >> m;
	for(int i = 1; i <= n ; i++){
		cin >> a[i];
		st[a[i]]++;
	}
	for(int i = 1; i <= m; i++){
		if(st[i] == 0){
			cout << 0 << " ";
		}else{
			cout << n << " ";
		}
	}
	return 0;
}
