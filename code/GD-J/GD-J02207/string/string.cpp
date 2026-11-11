#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int gcd(int a,int b){
	while (b){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
} 
struct str{
	int len;
	char c;
} a[20000005];
str b[200005];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		int x;
		cin >> b[i].len;
		cin >> b[i].c;
	}
	int gd = b[1].len;
	for (int i = 2;i <= n;i++){
		gd = gcd(gd,b[i].len);
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++){
		while (b[i].len){
			cnt++;
			a[cnt].c = b[i].c;
			a[cnt].len = gd;
			b[i].len -= gd;
		}
	}
//	for (int i = 1;i <= cnt;i++){
//		cout << a[i].len << ' ' << a[i].c << endl;
//	}
	for (int i = 1;i <= cnt/2;i++){
		if (a[i].c != a[cnt-i+1].c){
			ans += a[i].len;
			a[cnt-i+1].c = a[i].c;
		}
	}
	cout << ans;
	return 0;
} 

