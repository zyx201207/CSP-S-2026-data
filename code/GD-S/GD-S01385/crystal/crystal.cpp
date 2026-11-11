#include <bits/stdc++.h>
using namespace std;

long long n,m,cnt;
long long a[500010];
long long c[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long k = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2;i <= n;i ++){
		c[i - 1] = a[i] - a[i-1];
	}
	sort(c + 1,c + n);
	for(int i = 1;i <= n;i ++){
		k++;
		cnt*=2;
		cnt += c[i];
		if(cnt > m)break;
	}
	cout << k;
	return 0;
} 
