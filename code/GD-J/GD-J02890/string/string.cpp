#include <bits/stdc++.h>
using namespace std;
int a[500005];
string c,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,w = 0;
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i] >> c[i];
	for (int j = 0;j < n;j++) for (int k = 0;k < a[j];k++) x += c[j];
	for (int l = 0;l <= c.size() / 2;l++) if(c[l] != c[c.size() - l - 1]) w++;
	cout << w;
	return 0;}
