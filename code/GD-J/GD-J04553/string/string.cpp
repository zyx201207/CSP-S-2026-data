#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int tot2 = 0;
	long long a[MAXN];
	long long n,tot = 0,ans,ans2;
	char c[MAXN];
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		tot2 += 1;
	}
	n = 1;
	for(int i = tot;i >= tot / 2;i -= 1){
		if(c[i] != c[n]){
			ans += a[i];
			ans2 += a[n];
		}
		n += 1;
	}
	cout << max(ans,ans2);
	return 0;
}
