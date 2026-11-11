#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
struct node{
	int n;
	char c;
};
node a[N]; 
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ll t;
	string s;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int x;
		char y;
		cin >> x >> y;
		a[i].n = x, a[i]. c = y;
	}
	int l = 1, r = t;
	ll ans = 0;
	while(l < r){
		while(a[l].n && a[r].n){
			if(a[l].c != a[r]. c) ans++;
			a[l].n--;
			a[r].n--;
		}
		if(a[l].n <= 0) l++;
		if(a[r].n <= 0) r--;
	}
	cout << ans;
	return 0;
}
