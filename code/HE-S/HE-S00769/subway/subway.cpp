#include<bits/stdc++.h>
using namespace std;
int m,n,d,r,a;
int c;
int b[10000];
int w[10000],t[10000],q[10000],z[10000],s[10000];
int main() {
	int p=0;
	int y=1;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>b[i];
		for(int j=1; j<=a; j++) {
			cin>>s[y];
			cin>>t[y];
			y++;
		}
	}
	for(int i=1; i<=r; i++) {
		cin>>q[i]>>z[i];
	}
	int o;
	int v=0;
	for(int i=1; i<=r; i++) {
		o=q[i];
		p=w[o];
		int minn=10000;
		while(o!=z[i]) {
			for(int i=1; i<=n; i++) {
				for(int j=v; j<=b[i]; j++) {
					if(s[j]==o) {
						p+=t[j];
						for(int k=v; k<=b[i]; k++) {
							if(s[j]==z[i]) {
								p=p+t[k];
								if(minn>p) {
									minn=p;
								}
							}
						}
					}
				}
				v+=b[i];
			}

		}
		cout<<minn;
	}
	return 0;
}
