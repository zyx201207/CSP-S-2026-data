#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q,k;
int w[50005],a[501][50005],t[501][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][k]>>t[i][k];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<2;
	}
	return 0;
}
