#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;
int n, x, ans, s = 1, cnt, len, now;
char c;

struct node{
	int st, ed;
	char th;
}a[N], q[N];

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	while(n--) {
		cin >> x >> c;
		if(cnt && a[cnt - 1].th == c) a[cnt - 1] = {a[cnt - 1].st, a[cnt - 1].ed + x, c};
		else a[cnt++] = {s, s + x - 1, c};
		s = a[cnt - 1].ed + 1;
		len += x;
	}
	len++;
	if(cnt == 1) {
		cout << 0;
		return 0;
	}
	int head = 0, tail = 0;
	for(int i = 0; i < cnt; i++) {
		if(a[i].st < len / 2 && a[i].ed > len / 2) {
			q[tail++] = {a[i].st, len / 2 - 1, a[i].th};
			q[tail++] = {len / 2, len / 2, a[i].th};
			q[tail++] = {len / 2 + 1, a[i].ed, a[i].th};
		}
		else if(a[i].st == len / 2 && a[i].ed > len / 2) {
			q[tail++] = {len / 2, len / 2, a[i].th};
			q[tail++] = {len / 2 + 1, a[i].ed, a[i].th};
		}
		else if(a[i].st < len / 2 && a[i].ed == len / 2) {
			q[tail++] = {a[i].st, len / 2 - 1, a[i].th};
			q[tail++] = {len / 2, len / 2, a[i].th};
		}
		else q[tail++] = a[i];
	}
	tail--;
	while(now < len / 2) {
		node now1 = q[head], now2 = q[tail];
		int len1 = now1.ed - now1.st + 1, len2 = now2.ed - now2.st + 1;
		char th1 = now1.th, th2 = now2.th;
		if(len1 < len2) {
			now = now1.ed;
			q[tail].ed -= len1;
			if(th1 != th2) ans += len1;	
			head++;
		}
		else if(len1 > len2) {
			now = now1.ed - len2;
			q[head].st += len2;
			if(th1 != th2) ans += len2;
			tail--;
		}
		else {
			now = now1.ed;
			if(th1 != th2) ans += len1;
			head++;
			tail--;
		}
	}
	cout << ans;
	return 0;
}

