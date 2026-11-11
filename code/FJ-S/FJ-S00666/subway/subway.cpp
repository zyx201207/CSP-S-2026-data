#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500008]; 
struct stu{
	int a,t;
};
vector<stu> mp[500008];
struct st{
	int id,step;
};
bool bj[500008];
long long bfs(long long be,long long en){
	memset(bj,false,sizeof(bj));
	queue<st> p;
	st w,r,g;
	w.id=be;
	w.step=0;
    p.push(w);
    bj[w.id]=true;
    while(!p.empty()){
    	st r=p.front();
    	p.pop();
    	if(en==r.id){
    		return r.step;
		}
    	for(int i=0;i<mp[r.id].size();i++){
    		if(bj[mp[r.id][i].a]==true){
    			continue;
			}
			g.id=mp[r.id][i].a;
			g.step=r.step+1;
			p.push(g);
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			stu g;
			cin>>g.a>>g.t;
			mp[i].push_back(g);
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<bfs(x,y)*mp[1][1].t+w[x]+w[y]<<"\n";
	}
	return 0;
} 
