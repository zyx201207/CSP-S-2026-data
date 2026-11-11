#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
int dp[maxn];
int a[maxn];
int d[maxn];
int n,m;
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		if(a[i-1]==a[i]) {
			cout << a[i];
			return 0;
		}
	}
return 0;
} 
