#include <bits/stdc++.h>
using namespace std;
int p[1000000],yy[1000000];
bool p1[1000000];
int main() {
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>p[i];
	}
	int i=1;
	while (i<=n) {
		for (int j=1; j<=m; j++) {
			p1[j]=0;
		}
		for (int k=i; k<=n; k++) {
			if (p1[p[k]]==0) {
				p1[p[k]]=1;
			} else {
				for (int j=1; j<=m; j++) {
					p1[j]=0;
				}
				p1[p[k]]=1;
			}
		}
		for (int j=1; j<=m; j++) {
			if (p1[j]==1) {
				yy[j]++;
			}
		}
		i++;
	}
	for (int j=1; j<=m; j++) {
		cout<<yy[j]<<" ";
	}
	return 0;
}
