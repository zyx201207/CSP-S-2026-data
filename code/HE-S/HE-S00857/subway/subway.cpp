#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,c,p,d;
int a[500][N],t[500][N],w[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1; i<=m; i++)	cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=p; i++) {
		int l,r,sum=0;
		cin>>l>>r;
		for(int j=l; j<=r; j++) {
			sum+=t[l][j];
		}
		cout<<sum+w[l]+w[r]<<"\n";
	}
	return 0;
}
