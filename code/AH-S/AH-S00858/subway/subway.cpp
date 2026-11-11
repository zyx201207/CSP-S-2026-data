#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],a[500001],t[500001],x,y,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<w[x]+w[y]+t[x]+t[y];
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
