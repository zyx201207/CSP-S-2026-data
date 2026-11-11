#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
struct node {
	int num;
	char str;
}s[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	int n;
	long long x = 0;
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> s[i].num >> s[i].str;
		x += s[i].num;
	}		
	long long ans = 0;
	int sa = 1,sb = n;
	char a,b;
	for (int i = 1;i <= x / 2;i ++) {
		if (s[sa].num > 0) {
			a = s[sa].str;
			s[sa].num --;
		}
		else {
			sa ++;
			if (s[sa].num > 0) {
				a = s[sa].str;
				s[sa].num --;
			}else if (sb < sa)break;
			else break;
		}
		if (s[sb].num > 0) {
			b = s[sb].str;
			s[sb].num --;
		}else {
			sb --;
			if (s[sb].num > 0) {
				b = s[sb].str;
				s[sb].num --;
			}else if (sb < sa) {
				break;
			}
			else break;
		}
		if (s[sb].num == s[sa].num and s[sa].num == 0 and sa == sb) {
			break;
		}
		if (a != b) {
			ans ++;
			int tmp = min(s[sa].num,s[sb].num);
			ans += tmp;
			s[sa].num -= tmp;
			s[sb].num -= tmp;
		}else {
			int tmp = min(s[sa].num,s[sb].num);
			s[sa].num -= tmp;
			s[sb].num -= tmp;
		}
	}
	cout << ans;
	return 0;
}
