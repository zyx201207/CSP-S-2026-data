#include<bits/stdc++.h>
using namespace std;
int chu[500005];
int xian[505][10];
int k;
int c,n,m,d,q,rx,ry;
struct xian{
	int xi;
	int en;
	int w;
}x[2500005];
bool v[500005];
int bfs(int rx,int ry){
	queue<pair<int,int>>q;
	q.push({rx,0});
	v[rx]=1;
	while(!q.empty()){
		auto [x1,s]=q.front(); 
		if(x1==ry)return s;
		for(int i=1;i<=m;i++){
			int sx=x[i].en;
			int ss=x[i].en;
			if(v[sx]==0){
				v[sx]=1;
				q.push({rx,ss+s});
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>chu[i];
	} 
	if(1){
		for(int j=1;j<=m;j++){
		cin>>k;
	for(int i=1;i<=k;i++){
		cin>>x[i].en>>x[i].w;
		x[i].xi=j;
	}
}
	for(int i=1;i<=q;i++){
		cin>>rx>>ry;
		cout<<bfs(rx,ry)+chu[rx]+chu[ry]<<"\n";
	}
}
	return 0;
} 
