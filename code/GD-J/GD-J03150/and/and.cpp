#include <bits/stdc++.h>
using namespace std;
int maxa=0;
int n,m,a[200005],b[200005];
void dfs(int p,int last) {
	if (p==m+1) {
		int t=a[b[1]];
		for (int i=2;i<=m;i++) t&=a[b[i]];
		maxa=max(maxa,t); 
	}
	for (int i=last+1;i<=n-m+p;i++) {
		b[p]=i;
		dfs(p+1,i);
	}
}
int main() {
    freopen("end.in","r",stdin);
    freopen("end.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    dfs(1,0);
    cout <<maxa;
    return 0;
}
