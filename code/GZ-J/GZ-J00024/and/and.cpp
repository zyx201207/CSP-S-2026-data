//GZ-J00024 向子睿 云岩区实验中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000010;
int n, m, lena, lenb, a[maxn], b[maxn], ans;
unsigned long long rp = 0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	rp--;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	lena = n;
	for(int i = 30; i >= 0; i--){
		lenb = 0;
		for(int j = 1; j <= lena; j++){
			if(a[j] & (1 << i))b[++lenb] = a[j];
		}if(lenb >= m){
			for(int j = 1; j <= lenb; j++)a[j] = b[j];
			lena = lenb;
			ans += (1 << i);
		}
	}cout << ans;
	return 0;
}
