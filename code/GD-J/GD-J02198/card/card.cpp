#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],sum[300030];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		int v[500050],now=0;
		for(int j=i; j<=n; j++) {
			for(int k=1; k<=now; k++) {
				if(v[k]==a[j]) {
					now=k-1;
					break;
				}
			}
			v[++now]=a[j];
		}
		for(int j=1; j<=now; j++) sum[v[j]]++;
	}
	for(int i=1; i<=m; i++) cout<<sum[i]<<" ";
	return 0;
}
