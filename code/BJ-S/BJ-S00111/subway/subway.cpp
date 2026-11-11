#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,t;
};
struct node2{
	int x,sum,bl;
};
int c,n,m,d,qq,w[500005],q1[100005],q2[100005];
vector<node>vt[505],ct[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vt[i].push_back({a,t});
			ct[a].push_back({i,t});
		}
	}
	for(int i=1;i<=qq;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=qq;i++){
		int x=q1[i],y=q2[i],ans=1e9;
		queue<node2>q;
		q.push({x,w[x],0});
		while(!q.empty()){
			node2 t=q.front();
			q.pop();
			if(t.x==y){
				int s=0;
				for(auto y:ct[t.x]){
					if(y.a==t.bl)s=y.t;
				}
				ans=min(ans,t.sum+s+w[y]);
				continue;
				//break;
			}
			if(t.sum>=ans)continue;
			if(t.bl==0){
				for(node y:ct[t.x]){
					q.push({t.x,t.sum+y.t,y.a});
				}
			}else{
				int s=0;
				for(node y:vt[t.bl]){
					if(y.a==t.x)s=y.t;
					if(y.a!=t.x){
						q.push({y.a,t.sum+y.t,0});
					}
				}
				for(node y:ct[t.x]){
					if(y.a!=t.bl){
						q.push({x,t.sum+y.t+s,y.a});
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
