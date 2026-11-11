#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[200005],l[500005],w[200005],flag=1;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) { 
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		memset(l,0,sizeof(l));
		memset(w,0,sizeof(w));
		int idx=n-i;
		for(int j=n-i+1; j<=n; j++) {
			if(w[a[j]]==0||w[a[j]]>idx||l[w[a[j]]]!=a[j]) l[++idx]=a[j],w[a[j]]=idx;
			else {
				idx=w[a[j]];
				l[idx]=a[j];
			}
		}
		for(int j=n-i+1; j<=idx; j++) ans[l[j]]++;
	}
	for(int i=1; i<=m; i++) cout << ans[i] << " ";
	return 0;
}
