#include <bits/stdc++.h>
using namespace std;

#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa << 3) + (aa << 1) + (ch ^ 48);
		ch = getchar();
	}
	return aa * f;
}

const int N = 5e5+10;

int n, m;
int a[N];
int d[N], s[N];
int lst[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i<=n;i++) {
		a[i] = read();
		lst[a[i]] = i;
	}
	for(int i = 1;i<=n;i++) {
		int t = i-s[i-1];
		d[i]+=t, d[lst[a[i]]]-=t;
		s[i] = s[i-1] + d[i];
//		cout<<i<<" "<<s[i]<<"\n";
	}
	for(int i = 1;i<=m;i++)
		cout<<lst[i]-s[lst[i]]<<" ";
	return 0;
}
