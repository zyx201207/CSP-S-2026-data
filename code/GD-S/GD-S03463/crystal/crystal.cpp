#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long a[500005], b[500005], c[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	
//	for(int i=1;i<=n;i++)
//		printf("%lld ", a[i]);
	//cout << endl;
	
	for(int i=2;i<=n;i++) {
		b[i] = a[i]-a[i-1];
//		c[i] = c[i-1]+b[i]*(i-1);
//		cout << b[i] << ' ';
	}
	
	int maxn = 0;
	for(int i=1;i<=n;i++) {
		memset(c, 0, sizeof(c));
		for(int j=i;j<=n;j++) {
			c[j] = c[j-1]+b[j]*(j-i);
			maxn = max(maxn, j-i+1);
			if(m-c[j] < b[j+1]*(j)) break;
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

