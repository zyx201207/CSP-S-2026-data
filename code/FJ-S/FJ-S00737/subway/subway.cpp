#include<bits/stdc++.h>
#define ul unsigned long long
using namespace std;
struct sb{
	ul a,b;
};
struct tim{
	ul z,s;
};
vector<sb> e[505];
vector<sb> f[500005];
ul csdbh,n,m,zdzd,q,w[500005],ans;
void bfs(ul x,ul y){
	queue<tim> q;
	q.push({1,w[x]+w[y]});
	while(!q.empty()){
		tim u=q.front();
		q.pop();
		if(u.z==y){
			ans=min(ans,u.s);
			continue;
		} 
		for(sb x:f[u.z]){
			for(sb v:e[x.a]){
				q.push(v.a,u.s+);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%llu%llu%llu%llu%llu",&csdbh,&n,&m,&zdzd,&q);
	for(int i=1;i<=m;i++)scanf("%llu",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			ul x,y;
			scanf("%llu%llu",&x,&y);
			e[i].push_back({x,y});
			f[x].push_back({i,j});
		}
	}
	for(int i=0;i<q;i++){
		ul x,y;
		scanf("%llu%llu",&x,&y);
		bfs(x,y);
	}
	return 0;
}//Ciallo~ (///v///)~*
