#include<bits/stdc++.h>
using namespace std;
int N=2000010;
int c,n,m,d,q,w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;m++){
		cin>>w[i];
	}
	int k,x;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}