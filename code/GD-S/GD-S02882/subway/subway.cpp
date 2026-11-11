#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505,maxm=3e5+10;
int n,m,zt[maxm],dist[maxm],vis[maxm],ti[maxn][maxm];
vector<int>g[maxn];
vector<int>line[maxm];
struct que{
	int s,e,id;
};
bool cmp(que a,que b){
	return a.s<b.s;
}
que ans1[100001];
int ans2[100001];
void djstl(int st,int ed){
	for(int i=1;i<=m;i++)dist[i]=LLONG_MAX;
	memset(vis,0,sizeof(vis));
	queue<int>qu;
	qu.push(st);
	dist[st]=zt[st];
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int vl:line[u]){
			int d=ti[vl][u];
			for(int v:g[vl]){
				if(dist[u]+d+ti[vl][v]<dist[v]){
					qu.push(v);
					dist[v]=dist[u]+d+ti[vl][v];
				}
			}
		} 
	}
	return;
}
signed main(){
	int c,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&zt[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,tim;
			scanf("%lld %lld",&a,&tim);
			g[i].push_back(a);
			ti[i][a]=tim;
			line[a].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		scanf("%lld %lld",&st,&ed);
		ans1[i].s=st;
		ans1[i].e=ed;
		ans1[i].id=i;
	}
	int lastst=-1;
	sort(ans1+1,ans1+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(lastst!=ans1[i].s){
			djstl(ans1[i].s,ans1[i].e);
		}
		ans2[ans1[i].id]=dist[ans1[i].e]+zt[ans1[i].e];	
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans2[i]);
	}
}
