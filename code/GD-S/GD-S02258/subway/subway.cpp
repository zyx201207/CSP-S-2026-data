#include<bits/stdc++.h>
using namespace std;
struct no{
	int v;
	long long w;
	bool operator<(const no &a)const{
		return w>a.w;
	}
};
vector<no>g[505];
vector<int>a[100005];
long long ds[100005]={0};
priority_queue<no>q;
void dj(int be){
	ds[be]=0;
	q.push({be,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		for(int i:a[u]){
			long long sz;
			for(no j:g[i]){
				if(j.v==u){
				sz=j.w;
				break;}
			}
			for(no j:g[i]){
				if(ds[j.v]>ds[u]+j.w+sz){
					ds[j.v]=ds[u]+j.w+sz;
					q.push({j.v,ds[j.v]});
				}
			}
		}
	}
}
vector<no>qu[100005];
int an[100005];
long long w[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1,x,y;j<=k;j++){
			scanf("%d%d",&x,&y);
			g[i].push_back({x,y});
			a[x].push_back(i);
		}
	}
	int id=0;
	while(q--){
		++id;
		int x,y;
		cin >> x >> y;
		qu[x].push_back({y,id});
	}
	for(int i=1;i<=n;i++){
		if(qu[i].size()){
			memset(ds,127,sizeof(ds));
			dj(i);
			for(no j:qu[i]){
				an[j.w]=ds[j.v]+w[i]+w[j.v];
			}
		}
	}
	for(int i=1;i<=id;i++){
		printf("%d\n",an[i]);
	}
	return 0;
}
