//GZ-S00204 何奇峰宇 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5;

struct E{
	int v,w;
}e[N];

int c,n,m,d,q,w[N],x,y,idx;

void solve(int u,int v){

}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	while(c--){
		cin>>n>>m>>d>>q;
		vector<int> to(n*m);
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
				cin>>x;
				vector<int> y,ww;
			for(int j=1;j<=x;j++){
				cin>>y[j]>>ww[j];
			}
			for(int j=1;j<x;j++){
				e[j].w=ww[j];
				e[y[j]].v=y[j+1];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			solve(x,y);
		}
	}
	return 0;
}
