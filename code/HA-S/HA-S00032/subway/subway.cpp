#include<bits/stdc++.h>
using namespace std;
int c, n, m, d,q;
int k,ans,e=1e9;
int w[50010];
int a[510][50010];
int t[510][50010];
int f(int x,int r,int num,int s) {
	if(x==r) {
		e=min(e,num);
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(i==s)continue;
		for(int j=1; j<=k; j++) {
			if(a[i][j]==x) {
				num+=t[i][j];
				num+=t[i][j+(j==1?1:-1)];
				f(a[i][j+(j==1?1:-1)],r,num,i);
			}
		}
	}
	return e;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,r;
	cin>>c, n, m, d, q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int l=1; l<=q; l++) {
		cin>>x>>r;
		ans+=w[x]+w[r];
		ans+=f(x,r,0,0);
	}
	cout<<ans;
	return 0;
}
