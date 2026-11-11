#include <bits/stdc++.h>
#define lint long long
using namespace std;
string strn;
lint t;
lint x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	lint n;
	cin >> n;
	for(lint i=1;i<=n;i++) {
		lint a;
		cin >> a;
		char c;
		cin >> c;
        for(lint j=1;j<=a;j++) strn+=c;
		x += a;
	}
	for (lint i=0;i<x/2;i++) if(strn[i] != strn[x-1-i]) t++;
	cout << t;
	return 0;
}
