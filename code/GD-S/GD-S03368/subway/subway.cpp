#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[1000000],y[100000],x[100000],w[100000],a[100000][100000],t[100000][100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int s;
		s=w[x[i]]+n*t[1][1]+w[y[i]];
		cout<<s;
	}	
} 
