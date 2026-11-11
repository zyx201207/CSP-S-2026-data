#include<bits/stdc++.h>
using namespace std;
int w[500001];
int a[501][500001];
int t[501][500001];
int k[501];
int x[100001];
int y[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ti=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r];
		cin>>y[r];
	}
	for(int r=1;r<=q;r++){
		for(int i=1;i<=n;i++){
			for(int j=1;i<=n;j++){
				if(a[i][j]==x[r]){
					ti+=(w[i]+t[i][j]);
				}
				
			}
		}
	}
	cout<<ti;
	return 0;
}
