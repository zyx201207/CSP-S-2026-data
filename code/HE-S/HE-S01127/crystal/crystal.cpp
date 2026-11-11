#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,o=0;
	cin>>n>>m;
	int r;
	for(int i=1; i<=n; i++) {
		cin>>r;

		for(int j=1; j<=n; r--) {
			int p=r/2;
			if(r<=p) {
				int g=p-r;
				m-p;
				if (m-p) {
					o++;
				}
			}
		}
	}
	cout<<o;
	return 0 ;
}


