#include <bits/stdc++.h>
using namespace std;
string a,d;
long long n,x,ans,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> x;
		l += x;
		cin >> d;
		for (int j = 1;j <= x;j++)
			a += d;
	}
	for (int i = 1;i <= l / 2;i++)
		if (a[i] != a[l - i - 1])
			ans++;
	cout << ans;
	return 0;
}
