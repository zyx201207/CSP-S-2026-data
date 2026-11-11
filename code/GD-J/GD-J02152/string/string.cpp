#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, a[N];
char c[N];
signed main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		cin >> c[i];
	}
	int ans = 0;
	int st = 1, ed = n, q = a[1], w = a[n];
	while(st < ed){
		int x = min(q, w);
		if(c[st] != c[ed]){
			ans += x;
		}
		q-=x,w-=x;
		if(q==0){
			st++;
			q = a[st];
		}
		if(w==0){
			ed--;
			w=a[ed];
		}
	}
	cout << ans << endl;
	return 0;
} 
