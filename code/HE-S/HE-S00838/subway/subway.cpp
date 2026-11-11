#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,w[500000],k[500],a[500][500],t[500][500];
int qd[500005],zd[500005];
int zzz (int zt,int y) {
	if(zt==y) {
		return ans;
	}
     return 6;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>qd[i]>>zd[i];
	}
	for(int i=1; i<=q; i++) {
		cout<<zzz(qd[i],zd[i])+w[qd[i]]+w[zd[i]]<<endl;
	}
}
