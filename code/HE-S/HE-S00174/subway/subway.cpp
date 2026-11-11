#include<bits/stdc++.h>
using namespace std;
int w[500005],p[501][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int l;
		int a,b,c;
		cin>>l;
		for(int k=1;k<=l;k++){
			cin>>a>>b;
			p[c][a]=b;
			p[a][c]=b;
			c=a;	
		}
	}
	for(int i=1;i<=q;i++){
		int e,r;
		cin>>e>>r;
		
	}
	return 0;
}
