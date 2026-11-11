#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	const int MAXN = 2000005;
	int n,m;
	long long num = 0,a[MAXN];
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		num = min(num,a[i]);
	}
	
	cout << num;
	return 0;
} 
