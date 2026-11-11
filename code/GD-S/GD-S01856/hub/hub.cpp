#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch=='-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa<<3) + (aa<<1) + (ch^48);
		ch = getchar();
	}
	return aa*f;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T_T = read();
	while(T_T--)
		cout<<rand()%50000+1;
	return 0;
}
