#include<bits/stdc++.h>
using namespace std;
int a[500][50000],t[500][50000],d,n,m;
int as(int x,int y,int s){
	if(x==y){
		return s;
	}
	int a1[d+1];
	for(int i=1;i<=n;i++){
		if(a[i][1]==x){
			x=a[i][2];
			s=s+w[i]+t[i][1];
			as(int x,int y,int s);
		}
	}
}
int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],x[q+1],y[q+1],k[n+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
		cout<<as(x[r],y[r],0);
	}
	return 0;
}
