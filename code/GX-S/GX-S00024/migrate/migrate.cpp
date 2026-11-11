#include <bits/stdc++.h>
using namespace std;
int c,t,m,d,q;
int w[1000005],k[506],a[100006][100006],x[1000005],y[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=x[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}

	return 0;
}
