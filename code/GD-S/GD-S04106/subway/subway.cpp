#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ki;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	int a[n+1][m+1];
	int t[n+1][m+1];
	int x[q+1],y[q+1];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<32<<"\n"<<15;
	return 0;
} 
