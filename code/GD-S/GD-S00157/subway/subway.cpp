#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
struct node{
	int v,t;
	const bool operator<(const node&b)const{
		return t!=b.t?t>b.t:v>b.v;
	}
};
int n,m,C,d,Q,w[500001],st,ed,k;
vector<node>g[500501],s[501];
map<int,map<int,int>>vis;
void dj(int st){
	priority_queue<node>q;q.push({st,0});
	while(q.size()){
		node h=q.top();q.pop();
		if(vis[st][h.v]>0)continue;
		if(h.v>m)vis[st][h.v]=-1;
		else s[st-m].push_back({h.v,h.t}),vis[st][h.v]=s[st-m].size();
		for(node i:g[h.v]){
			if(vis[h.v][i.v])continue;
			q.push({i.v,h.t+i.t});
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	C=rd(),n=rd(),m=rd(),d=rd(),Q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++){
		k=rd();
		while(k--)st=rd(),ed=rd(),g[i+m].push_back({st,ed}),g[st].push_back({i+m,ed});
	}
	for(int i=1+m;i<=n+m;i++)dj(i);
	while(Q--){
		st=rd(),ed=rd(),k=0x3f3f3f3f;
		for(int i=1+m;i<=n+m;i++){
			if(!vis[i][st]||!vis[i][ed])continue;
			k=min(k,s[i-m][vis[i][st]-1].t+s[i-m][vis[i][ed]-1].t);
		}
		printf("%lld\n",k+w[st]+w[ed]);
	}
	return 0;
} 
