#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node{
	int x;
	char c;
} a[200001];

int n,ans;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].c;
	}
	int l = 1,r = n,idl = 1,idr = 1;
	while (l < r){
		int add = min(a[l].x - idl + 1,a[r].x - idr + 1);
		if (a[l].c != a[r].c){
			ans += add; 
		}
		idl += add;
		idr += add;
		if (idl > a[l].x){
			l++;
			idl = 1;
		}
		if (idr > a[r].x){
			r--;
			idr = 1;
		}
	}
	cout << ans;
	return 0;
} 
