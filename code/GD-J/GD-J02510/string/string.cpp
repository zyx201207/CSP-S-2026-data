#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
struct node{
	long long l, r;
	char c;
}d[maxn];
long long n, ans = 0;

int fnd(long long val){
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(d[mid].l > val) r = mid - 1;
		else if(d[mid].r < val) l = mid + 1;
		else if(d[mid].l <= val && d[mid].r >= val) return mid;
	}
	return r;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false); 
	cin.tie(0);
	
	cin >> n;
	long long nlen = 0;
	for(int i = 1; i <= n; i++){
		long long ll;
		char cc;
		cin >> ll >> cc;
		d[i].l = nlen + 1;
		d[i].r = nlen + ll;
		d[i].c = cc;
		nlen += ll;
	}
	for(long long i = 1; i <= nlen / 2; ){
		int b1 = fnd(i), b2 = fnd(nlen + 1 - i);
		long long l1 = d[b1].l, r1 = d[b1].r, l2 = d[b2].l, r2 = d[b2].r;
		char c1 = d[b1].c, c2 = d[b2].c;
		long long len1 = r1 - i + 1, len2 = nlen + 1 - i - l2 + 1;
		long long len = min(len1, len2);
		if(c1 != c2) ans += len;
		i += len;
	}
	cout << ans;
}

//Trick||Treat!
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

