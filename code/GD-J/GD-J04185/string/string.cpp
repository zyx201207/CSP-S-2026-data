#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,tot;
char s[200005];
string sums;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
		for (int j = 1;j <= a[i];j++){
			sums += s[i];
		}
	}
	tot = sums.size();
	for (int i = 0;i * 2 < tot;i++){
		if (sums[i] != sums[tot - 1 - i]){
			ans++;
		}
	}
	cout << ans;
}

