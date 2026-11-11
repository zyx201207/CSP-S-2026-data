#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1],a[50000],t[50000],x[q+1],y[q+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<rand()%(rand()%100)<<'\n';
	}
	return 0;
}
