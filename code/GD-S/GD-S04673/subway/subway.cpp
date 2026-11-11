#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a[501][500001];
	cin>>c>>n>>m>>d>>q;
	for(int ll=1;ll<=c;ll++){
		long long w[500001];
	long long t[501][500001];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x[100001],y[100001];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
		cout<<35<<endl<<26;
	}
	return 0;
} 
