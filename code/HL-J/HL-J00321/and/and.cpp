#include <bits/stdc++.h>
using namespace std;
int n,m,b[200005];
long long a[200005],sum,x = 1;
void dfs(int x,long long ans) {
	if(x == m+1) {
		sum = max(sum,ans);
	}
	for(int i = 1;i<=n;i++) {
		if(b[i] == 0) {
			if(ans>sum) {
				b[i] = 1;
				dfs(x+1,ans&a[i]);
				b[i] = 0;
			}
		}
	}
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
    	cin>>a[i];
	}
	for(int i = 1;i<=30;i++) {
		x*=2;
	}
	x = x+(x-1);
	
	if(m == n) {
		sum = a[1];
		for(int i = 2;i<=n;i++) {
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	dfs(1,x);
	cout<<sum;
    return 0;
}
