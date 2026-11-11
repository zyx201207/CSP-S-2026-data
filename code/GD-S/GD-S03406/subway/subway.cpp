#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500005]={};
struct xxx{
	int id,t,r;
};
vector< vector< xxx > > mp(500005);
vector<int> st(500005);


queue<xxx> s;
bool dis[500005];
long long bfs(int x,int y){
	dis[x]=1;
	s.push({x,0,-1});
	xxx t;
	while(!s.empty()){
		t=s.back();
		s.pop();
		if(t.id==y) return t.t;
		for(int i=0;i<mp[i].size();i++){
			if(dis[mp[t.id][i].r]==0){
				xxx x;
				if(mp[t.id][i].r!=t.r){
					x.id=mp[t.id][i].id;
					x.t=t.t+mp[t.id][i].t+st[t.id];
					x.r=mp[t.id][i].r;
					s.push(x);
				}else{
					s.push({mp[t.id][i].id,t.t+mp[t.id][i].t,mp[t.id][i].r});
				}	
				dis[mp[t.id][i].r]=1;		
			}

		}
	}
	return t.t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
//	for(int i=1;i<=m;i++) cout<<w[i]<<' ';
	int k;
	for(int i=1;i<=n;i++){
		scanf("%d",&k); 
		int x1,x2;
		int y1,y2;
 		scanf("%d%d",&x1,&x2);
 		st[x1]=x2;
 		for(int j=0;j<k-1;j++){
//			cout<<k;
 			scanf("%d%d",&y1,&y2);
 			mp[x1].push_back({y1,y2,i});
 			mp[y1].push_back({x1,x2,i});
 			x1=y1;
 			x2=y2;
		}
		st[x1]=x2;
	}
	long long ans=0;
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);
		ans+=w[s]+w[e];
		ans+=bfs(s,e);
		printf("%lld\n",&ans);
	}
//	for(int i=0;i<3;i++){
//		for(int j=0;j<mp[i].size();j++){
//			printf("%d %d %d	",mp[i][j].id,mp[i][j].t,mp[i][j].r);
//		}
//		printf("\n");
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
