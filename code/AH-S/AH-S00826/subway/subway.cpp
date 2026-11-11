#include<bits/stdc++.h>
using namespace std;
int z[20005][3],w[20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,t;
	cin>>c>>n>>m>>d>>t;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int g;
		cin>>g;
		for (int j=1;j<=g;j++){
			int y,u;
			cin>>y>>u;
			z[y]; 
		}
	}
	while (t--){
		int f,e;
		cin>>f>>e;
		int rans=z[e][0]+z[f][0];
		
	}
	return 0;
}
