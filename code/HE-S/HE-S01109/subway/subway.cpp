#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x;
		for(int j=1;j<=k[i];j++){
			cin>>x;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y];
	}
	return 0;
}
