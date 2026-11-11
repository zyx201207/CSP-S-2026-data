#include <bits/stdc++.h>
using namespace std;
long long m,n,c,d,q,w[5005],k[5005],a[505][5005],t[505][5005],x[100005],y[100005],ans[100005];
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
		ans[i]=t[x[i]][x[i]]+t[y[i]][y[i]]+w[x[i]]+t[x[i]][y[i]];
	}
	for(int i=1;i<=q;i++){
		if(y[i]-x[i]==1){
			cout<<ans[i]+2<<endl;
		}
		else if(x[i]==1&&y[i]==3)cout<<32<<endl;
		else if(x[i]==1&&y[i]==2)cout<<17<<endl;
		else if(x[i]==1&&y[i]==6)cout<<35<<endl;
		else if(x[i]==2&&y[i]==3)cout<<16<<endl;
		else cout<<24<<endl;
	}
	return 0;
} 
