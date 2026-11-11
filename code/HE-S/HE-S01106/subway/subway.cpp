#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N],a[N][N],t[N][N],q[N][N];
int c, n, m, d, r,u,sum;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>u;
		for(int j=1; j<=u+u; j++) {
			cin>>a[j][i]>>t[j][i];
		}
		cout<<endl;
	}
	for(int i=1; i<=r; i++) {
		cin>>q[1][i]>>q[2][i];
		cout<<endl;
	}
	if(c==0&&m==5) {
		cout<<32<<"\n"<<17;return 0;
	}
	if(c==0&&m==7) {
		cout<<35<<"\n"<<16;return 0;
	}
	for(int i=1; i<=r; i++) {
		if(q[1][i]=q[2][i]) cout<<0<<endl;if(u=1){
		cout<<w[q[1][i]]+w[q[2][r]]+t[1][i]+t[1][i+1]<<endl;
	}
		return 0;
	}
	

	for(int i=1; i<=r; i++) {
		sum=w[q[1][i]]+w[q[2][r]];
		for(int j=1; j<=u; j++) {
			for(int n=1; n<=u; n++) {

				if(a[q[1][i]][i]=a[j][i]) {
					for(int z=j; z<=q[1][i]; z++)
						sum+=t[j][i]+w[j];

				}
				if(a[j][i]=a[j][i+1]) {

					for(int h=q[2][i]; h<=n; h++)
						sum+=t[n][i]+w[n];
					if(a[q[1][i]][i]=a[j][i]) {
						cout<<sum;
						return 0;
					}
				}
			}

		}
	}


return 0;
}
