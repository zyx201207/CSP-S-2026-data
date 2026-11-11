#include<bits/stdc++.h>
using namespace std;
long long n, now;
struct D{
	long long l, r;
	char c;
}d[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		long long a; char c;
		cin >> a >> c;
		d[i].c = c;
		d[i].l = now + 1;
		d[i].r = now + a;
		now += a;
	}
	if (now % 2 != 0){
		long long mid = now / 2 + 1, ans = 0, l = 1, r = d[n].r, lt = 1, rt = 1;
		for (int i = 1; i <= n; i++)
			if (d[i].l <= mid && d[i].r >= mid){
				lt = rt = i;
				l = d[i].l; r = d[i].r;
				//ans = ans + (max(d[i].r - mid, mid - d[i].l) - min(d[i].r - mid, mid - d[i].l));
			}
		while (lt >= 1 && rt <= n){
			if (lt == 1 && rt == n){
				cout << ans;
				break;
			}
			if (r - mid > mid - l){
				lt--;
				if (d[lt].c != d[rt].c)
					ans += r - mid - (mid - l);
				l = d[lt].l;
			}
			else if (r - mid < mid - l){
				rt++;
				if (d[lt].c != d[rt].c)
					ans += mid - l - (r - mid);
				r = d[rt].r;
			}
			while (r - mid == mid - l && lt >= 1 && rt <= n){
				if (lt == 1 && rt == n)
					break;
				lt--; rt++;
				l = d[lt].l; r = d[rt].r;
				if (d[lt].c != d[rt].c)
					ans += min(d[lt].r - d[lt].l + 1, d[rt].r - d[rt].l + 1);
			}
		}
	}
	if (now % 2 == 0){
		long long midr = now / 2 + 1, midl = now / 2, ans = 0, l = 1, r = d[n].r, lt = 1, rt = 1;
		for (int i = 1; i <= n; i++){
			if (d[i].l <= midl && d[i].r >= midl){
				lt = i;
				l = d[i].l;
				//ans = ans + (max(d[i].r - mid, mid - d[i].l) - min(d[i].r - mid, mid - d[i].l));
			}
			if (d[i].l <= midr && d[i].r >= midr){
				rt = i;
				r = d[i].r;
				//ans = ans + (max(d[i].r - mid, mid - d[i].l) - min(d[i].r - mid, mid - d[i].l));
			}
		}
		if (d[lt].c != d[rt].c)
			ans += min(d[lt].r - d[lt].l + 1, d[rt].r - d[rt].l + 1);
		while (lt >= 1 && rt <= n){
			if (lt == 1 && rt == n){
				cout << ans;
				break;
			}
			if (r - midr + 1 > midl - l + 1){
				lt--;
				if (d[lt].c != d[rt].c)
					ans += r - midr + 1 - (midl - l + 1);
				l = d[lt].l;
			}
			else if (r - midr + 1 < midl - l + 1){
				rt++;
				if (d[lt].c != d[rt].c)
					ans += midl - l + 1 - (r - midr + 1);
				r = d[rt].r;
			}
			while (r - midr + 1 == midl - l + 1 && lt >= 1 && rt <= n){
				if (lt == 1 && rt == n)
					break;
				lt--; rt++;
				l = d[lt].l; r = d[rt].r;
				if (d[lt].c != d[rt].c)
					ans += min(d[lt].r - d[lt].l + 1, d[rt].r - d[rt].l + 1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//aaaaaaa dddddd ffffff fffffff bbbb aaaaaaa gg
//                      m       dddd dd      aa
//39
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
//aaaaa ddddd bbbbb aaaaa
//aaaaaaa aaaaaaa aaaaaaa bbbbbbb bbbbbbb bbbbbbb
//aaaabbbbaaaaaaaabbbaaaannnfffffffaaccc
//ccc afffffffnnn aaa
//cccaafffffffnnnaaaa aaaannnfffffffaaccc
//aaa ddd vvvv xxx bbb nnnnn f
