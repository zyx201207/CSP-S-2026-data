#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans[500005],w[500005];
vector<pair<int,int> > edge[500005];
priority_queue<pair<int ,int >,vector<pair<int,int> >,greater<pair<int,int> > >p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,a,ti;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&ti);
			edge[i].push_back({a,2*ti});
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		while(!p.empty()) p.pop();
		for(int i=1;i<=m;i++) ans[i]=2000000000;
		p.push({0,s});
		ans[s]=0;
		while(!p.empty()){
			int x=p.top().first,y=p.top().second;
			p.pop();
			if(ans[y]!=x) continue;
			for(auto j:edge[y]){
				int sx=j.first;
				if(ans[sx]>ans[y]+j.second){
					ans[sx]=ans[y]+j.second;
					p.push({ans[sx],j.first});
				}
			}
		}
		printf("%d\n",ans[t]+w[s]+w[t]);
	}
	return 0;
} 
