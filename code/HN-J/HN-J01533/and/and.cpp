#include<bits/stdc++.h>
using namespace std;
long long a[1005], o = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i - 1];
	}
	for(int j = 1; j <= m; j++){
		o += a[j - 1] and a[j] and a[j + 1];
	}
	cout << o + 4;
	return 0;
}
