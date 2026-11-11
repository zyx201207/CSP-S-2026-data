#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],k[200002],sz[200001],cf;
bool cc(int s) {
	for(int i=0; i<=m; i++) {
		if(s==k[i+1]) {
			cf=i+1;
			return 0;
		}
		if(k[i+1]==0) {
			return 1;
		}
	}
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[n];
	}
	int d=1;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(cc(a[j])) {
				k[d++]=a[n];
			} else {
				while(d>cf) {
					k[d--]=0;
				}
			}


		}
	}
	for(int i=1; i<=m; i++) {
		sz[k[i]]++;
	}
	for(int i=1; i<=m; i++) {
		cout<<sz[i]<<' ';
	}
	return 0;
}
