#include <bits/stdc++.h>
using namespace std;
string b;long long c,s,n,a[200005];string z[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> z[i];
		c += a[i];}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= a[i];j++){
			b += z[i];}}
	for (int i = 1;i <= c / 2;i++){
		for (int j = c;j >= (c - 1) / 2 + 2;j--){
				if (z[i] != z[j]) s++;}}
	cout << s;
	return 0;}
