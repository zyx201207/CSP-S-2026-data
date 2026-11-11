#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int o,n,m,d,q,k;
int a[N],b[N][N],c[N][N],x[N],y[N];
int ba[N];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>n>>m>>d>>q;
	int maxx=-1;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[i][j]>>c[i][j];
			ba[b[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>x[i]>>y[i];
		}
	}
	cout<<ba;
	return 0;                        
}
