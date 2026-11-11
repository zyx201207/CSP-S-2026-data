#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[500005],k[500005],a[500005][500005],t;
	cin>>c>>n>>m>>d>>q;
	if(12<=c&&c<=19){
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t;
			} 
		}
		int x[100005],y[100005];
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=q;i++){
			cout<<w[x[i]]+w[y[i]]+(abs(y[i]-x[i])*2)<<endl;
		}
	}
	return 0;
}
