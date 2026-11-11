#include <bits/stdc++.h>
using namespace std;
long long n, a[200006], s;
char c[200006][6];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 1;i <= n;i++)
		scanf("%lld%c%c%c", &a[i], &c[i][0], &c[i][1], &c[i][2]);
	int l = 1, r = n;
	while (l <= r) {
		if (a[l] == a[r]){
			if (c[l][1] == c[r][1]) {//aabbfffaaba
				l++, r--; cout << "1" << s << endl;}
			else {
				s += a[l], l++, r--;cout << "2"  << s<< endl;}
		} else {
			if (a[l] > a[r]) {
				if (c[l][1]  == c[r][1]){
					a[l] -= a[r], r--;cout << "3" << s << endl;}
				else{
					s += a[r], a[l] -= a[r], r--;cout << "4" << s << endl;}
			} else {
				if (c[l][1]  == c[r][1]){
					a[r] -= a[l], l++;cout << "5" << s << endl;}
				else{
					s += a[l], a[r] -= a[l], l++;cout << "6" << s << endl;}
			}
		}
	}
	cout << s;
}
