#include <bits/stdc++.h>
using namespace std;
int f[605][605];
int w[205];
int c,n,m,d,q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=601;i++) {
		for (int j=1;j<=601;j++) {
			f[i][j]=100000005;
		}
		f[i][i]=0;
	}
	int top=m+1;
	for (int i=1;i<=n;i++) {
		int ki;
		cin>>ki;
		for (int j=1;j<=ki;j++) {
			int ai,ti;
			cin>>ai>>ti;
			if (j!=1) {
				f[top][top-1]=f[top-1][top]=0;
			}
			f[ai][top]=f[top][ai]=ti;
			top++;
		}
	}
	for (int i=1;i<=top;i++) {
		for (int j=1;j<=top;j++) {
			for (int k=1;k<=top;k++) {
				if (f[i][j]<100000005&&f[j][k]<100000005) {
					f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
					f[k][i]=min(f[k][i],f[k][j]+f[j][i]);
				}
			}
		}
	}
	for (int i=1;i<=q;i++) {
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]+f[l][r]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
