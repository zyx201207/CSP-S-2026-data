#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,w[50005],a[50005],t[50005],k[1001];
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
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x]+t[y];
	}
	
	return 0;
}
