#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200005;
int n, sum, a[MAXN], len;
char c[MAXN];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int i = 1, j = n;
	while(i <= j){
		if(a[i] >= a[j]){
			a[i] -= a[j];
			len -= a[j];
			if(c[i] != c[j]) sum += a[j];
			j--;
		}
		else{
			a[j] -= a[i];
			len -= a[i];
			if(c[i] != c[j]) sum += a[i];
			i++;
		}
		if(i == j){
			break;
		}
		if(i == j - 1){
			if(c[i] != c[j]) sum += min(a[i], a[j]);
			break;
		}
	}
	cout << sum;
	return 0;
}
