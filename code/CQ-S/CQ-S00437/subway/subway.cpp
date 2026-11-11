#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a,t,x,y,f[500505];
vector<pair<long long,long long> >v[500505];
priority_queue<pair<long long,long long> >p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld %lld",&a,&t);
			v[a].push_back({m+i,t});
			v[m+i].push_back({a,t});
		}
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
		for(int i=1;i<=m+n;i++) f[i]=1e18;
		p.push({w[x],x});f[x]=w[x];
		while(p.size()){
			int b=p.top().second;
			p.pop();
			for(int i=0;i<v[b].size();i++){
				if(f[v[b][i].first]>f[b]+v[b][i].second){
					f[v[b][i].first]=f[b]+v[b][i].second;
					p.push({f[v[b][i].first],v[b][i].first});
				}
			}
		}
		printf("%lld\n",f[y]+w[y]);
	}
	return 0;
} 
