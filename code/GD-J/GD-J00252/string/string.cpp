#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;	
const int N = 2e5 + 10;
struct node{
	ll l, r, len;
	char c;
}a[N];
int n;
ll ans, len = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].len >> a[i].c;
		a[i].l = len + 1, a[i].r = len + a[i].len;
		len += a[i].len;
	}
//	for(int i = 1; i <= n; i++){
//		cout << a[i].l << " " << a[i].r << '\n';
//	}
	for(int i = 1, j = n; i <= n; i++){
		ll ql = len - a[i].r + 1, qr = len - a[i].l + 1;
//		cout <<  ql << " " << qr << "\n";
		while(ql <= a[j].l && a[j].r <= qr){
			if(a[j].c != a[i].c)
				ans += (a[j].r - a[j].l + 1);
			qr = a[j].r - 1;
			j--;
		} 
		if(a[j].l <= ql && qr <= a[j].r){
			if(a[j].c != a[i].c)
				ans += (qr - ql + 1);
		}	
		if(i == j){
			cout << ans;
			exit(0);
		}
	}
	cout << ans;
	return 0;
}
