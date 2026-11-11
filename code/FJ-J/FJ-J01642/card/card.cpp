#include<bits/stdc++.h>
using namespace std;

int n,m,a[300000],as[300000],d[300000],bj[300000];
bool have[300000];

int main() {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int o=1,t=1;
		for(int j=n+1-i; j>=i; j--) {
			for(int y=j; y<=n; y++) {

				d[o]=a[y];
				if(have[a[y]]=1) {
					o=bj[d[o]];
					for(int p=o; p<=a[y]; p++) {
						have[p]=0;
					}

				}
				have[a[y]]=1;
				bj[d[o]]=o;
				o++;
			}
			memset(have,0,n);
			for(int r=1; r<=o; r++) {
				if(d[r]==i) {
					as[i]++;
				}
			}

		}
	}
	for(int i=1; i<=m; i++) {
		cout<<as[i]<<" ";
	}

	return 0;
}
