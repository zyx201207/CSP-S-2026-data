#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct L{
	int sta,w;
};
vector<int>station; 
L line[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	station.resize(m);
	for(int i=0;i<m;i++){
		cin>>station[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>line[i][j].sta>>line[i][j].w;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int cost=0;
		cost+=station[x]+station[y];
		cout<<cost+(y-x)*station[x]<<endl;
	}
	return 0;
}
