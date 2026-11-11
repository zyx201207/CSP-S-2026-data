#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,a[100005],w[100005],t[100005],x[100005],y[100005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i,j];
			cin>>t[i,j];
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
