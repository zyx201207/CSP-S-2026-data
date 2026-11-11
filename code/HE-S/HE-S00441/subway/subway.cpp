#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct p{
	int z,t=0;
}e[305];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> e[i].z;
	}
	for (int i=1;i<=n;i++){
		int k,u,v,w;
		cin >> k;
		for (int j=1;j<=k;j++){
			cin >> u >> w;
			e[u].t=w;
		}
	}
	while(q--){
		int i,j;
		cin >> i >> j;
		cout << (j-i)*e[i].t*2+e[i].z+e[j].z << endl;
	}
	return 0;
}
