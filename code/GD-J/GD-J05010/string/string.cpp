#include<bits/stdc++.h>
using namespace std;

long long n, ans, mi, i, j;
struct ASD{
	long long l;
	string s;
}a[200005];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (i=0; i<n; i++)
		cin >> a[i].l >> a[i].s;
	i=0;
	j=n-1;
	while (i<j){
		if (a[i].s==a[j].s){
			mi=min(a[i].l, a[j].l);
			a[i].l-=mi;
			a[j].l-=mi;
		} else {
			mi=min(a[i].l, a[j].l);
			a[i].l-=mi;
			a[j].l-=mi;
			ans+=mi;
		}
		if (a[i].l==0)
			i++;
		if (a[j].l==0)
			j--;
	}
	cout << ans << '\n';
	return 0;
}
