#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define Q 100005
int c,n,m,d,q;
int w[M];
vector<pair<int,int>> g[M<<1];
int dd[M];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> qq;
long long dis[M<<1];
void dij(int fr,int ed){
	fill(dis,dis+1+m+m,7e9);
	while(!qq.empty()) qq.pop();
	qq.push({0,fr});
	dis[fr]=0;
	while(!qq.empty()){
		int u=qq.top().second;
		long long weight=qq.top().first;
		qq.pop();
		if(dis[u]!=weight) continue;
		if(c>=12&&c<=19&&u==ed) return ;
		for(auto i:g[u]){
			int v=i.first;
			int w=i.second;
			if(weight+(long long)w<dis[v]){
				dis[v]=(long long)w+weight;
				qq.push({dis[v],v});
			}
		}
	}
}
struct node{
	int x,y,num;
}ask[Q];
bool cmp(node aa,node bb){
	return aa.x<bb.x;
}
long long ans[Q];
int rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void wr(long long x){
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	//cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=rd();
	}
	for(int i=1;i<=n;i++){
		int k,a,t,la=-1;
		k=rd();
		for(int j=1;j<=k;j++){
			a=rd();t=rd();
			dd[a]++;
			if(la!=-1){
				g[la+m+dd[la]-1].push_back({a+m+dd[a]-1,0});
				g[a+m+dd[a]-1].push_back({la+m+dd[la]-1,0});
			}
			g[a].push_back({a+m+dd[a]-1,t});//Ìü-Ì¨ 
			g[a+m+dd[a]-1].push_back({a,t});
			la=a;
		}
	}
	for(int i=1;i<=q;i++){
		ask[i].x=rd();ask[i].y=rd();
		ask[i].num=i;
		if(q<=2000){
			int x=ask[i].x,y=ask[i].y;
			dij(x,y);
			wr(dis[y]+w[x]+w[y]);
			putchar('\n');
		}
	}
	if(q<=2000) return 0;
	sort(ask+1,ask+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(i>1&&ask[i].x==ask[i-1].x){
			ans[ask[i].num]=dis[ask[i].y]+w[ask[i].x]+w[ask[i].y];
		}else{
			dij(ask[i].x,ask[i].y);
			ans[ask[i].num]=dis[ask[i].y]+w[ask[i].x]+w[ask[i].y];
		}
	}
	for(int i=1;i<=q;i++){
		wr(ans[i]);
		putchar('\n');
	}
	return 0;
}
