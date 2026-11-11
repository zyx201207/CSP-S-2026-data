#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],tot;
vector<pair<int,int>>vec[1000005],qa[500005];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
long long vm[1000005],ans[500005];
void bfs(int x){
	while(!pq.empty())pq.pop();
	memset(vm,0x3f,sizeof(vm));
	pq.push({(long long)0,x});
	while(!pq.empty()&&pq.top().first<=vm[pq.top().second]){
		auto t=pq.top();
		pq.pop();
		for(auto p:vec[t.second]){
			long long len=t.first+p.second;
			if(len<vm[p.first]){
				pq.push({len,p.first});
				vm[p.first]=len;
			}
		}
	}for(auto p:qa[x]){
		ans[p.second]=vm[p.first]+w[x]+w[p.first];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	tot=m;
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}for(int i=1;i<=n;++i){
		int k,a,t;scanf("%d%d%d",&k,&a,&t);
		++tot;
		vec[a].push_back({tot,t});
		vec[tot].push_back({a,t});
		for(int j=1;j<k;++j){
			++tot;
			scanf("%d%d",&a,&t);
			vec[a].push_back({tot,t});
			vec[tot].push_back({a,t});
			vec[tot].push_back({tot-1,0});
			vec[tot-1].push_back({tot,0});
		}
	}for(int i=1;i<=q;++i){
		int x,y;scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		qa[x].push_back({y,i});
	}for(int i=1;i<=m;++i){
		if(qa[i].empty())continue;
		bfs(i);
	}for(int i=1;i<=q;++i){
		printf("%lld\n",ans[i]);
	}
	return 0;
}