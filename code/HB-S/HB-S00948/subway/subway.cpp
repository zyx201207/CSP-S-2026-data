#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[500],t[500][500010];
int x[100010],y[100010],a[500][500010];
int main(){
	freopen("subeay.in","r",stdin);
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
		long long ans=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++)
			for(int f=1;f<=k[j];f++)
				if(a[j][f]==x[i] || a[j][f]==y[i]) ans+=t[j][f];
		cout<<ans<<endl;
	}
	return 0;
}
