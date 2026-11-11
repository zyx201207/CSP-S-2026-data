#include<bits/stdc++.h>
using namespace std;
int  c,n,m,d,q,dis[500005],w[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a>>t[j];
		} 	
	}	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dis[i]=w[x]+t[x]+t[x]+w[y];
		cout<<dis[y]<<endl;
	}
	return 0;
}
