#include<bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
#define int long long
struct jgt{
	int l;
	char s;
}e[N];
int n;
int js[250];
int minn = 2e18;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> e[i].l >> e[i].s; 
	}
	if(n == 1){
		cout << 0;
		return 0;
	} 
	for(int i = 1; i <= n; i++){
		js[e[i].s] += e[i].l;
	}
	for(int i = 1; i <= 200; i++){
		if(!js[i])continue;
	    minn = min(minn, js[i]);
	    
	}
	cout << minn;
	return 0;
} 
