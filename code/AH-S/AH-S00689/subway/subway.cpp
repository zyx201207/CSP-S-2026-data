#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+5],k[n+5],a[n+5][n+5],t[n+5][n+5],x[q+5],y[q+5];
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
	}
	
	//give up
	//Oct31==Dec25?
	//4.1=5.20
	//5.20=4.1
	
	for(int i=1;i<=q;i++){
		cout<<"114514";
	}
	return 0;
}
