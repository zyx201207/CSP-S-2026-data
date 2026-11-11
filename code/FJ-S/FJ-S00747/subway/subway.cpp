#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
template<typename T>void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=x*10+(c^48);c=getchar();}
	x*=f;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int top=0,c,n,m,d,q,x,subv,subt,dis[6666666],ans[555][555];
vector<pair<int,int>> g[6666666];
void ins(int xx,int yy,int zz){
	g[xx].push_back({yy,zz});
	g[yy].push_back({xx,zz});
}
void dij(int s){
	for(int i=1;i<=top;i++)dis[i]=1e18;
	//for(int i=1;i<=top;i++)cout<<dis[i]<<" ";
		//cout<<"\n";
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});dis[s]=0;
	while(!pq.empty()){
		auto p=pq.top();pq.pop();
		int v=p.second,w=p.first;
		//cout<<dis[v]<<" "<<w<<'\n';
		if(w>dis[v])continue;
		for(auto u:g[v]){
			int wi=u.second,vi=u.first;
			//cout<<vi<<' '<<wi<<'\n';
			if(dis[vi]>dis[v]+wi){
				dis[vi]=dis[v]+wi;
				pq.push({dis[vi],vi});
			}
		}
		//for(int i=1;i<=top;i++)cout<<dis[i]<<" ";
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++)ans[s][i]=dis[i];
}
signed main(){
	//freopen("subway.in","r",stdin);
	file("subway")
	memset(ans,-1,sizeof(ans));
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++)read(x),ins(i,m+i,x);
	top=2*m;
	for(int o=1;o<=n;o++){
		int kd;read(kd);
		//cout<<o<<"\n";
		for(int i=1;i<=kd;i++){
			read(subv);read(subt);
			ins(subv+m,++top,subt);
			if(i>=2)ins(top,top-1,0);
		}
	}
	/*for(int i=1;i<=20;i++){
		cout<<i<<":\n";
		for(auto j:g[i])cout<<j.first<<" "<<j.second<<'\n';
	}*/
	//cout<<"p";
	while(q--){
		int ss,tt;
		read(ss);read(tt);
		if(ans[tt][ss]==-1&&ans[ss][tt]==-1)dij(ss);
		if(ans[ss][tt]==-1)write(ans[tt][ss]);
		else write(ans[ss][tt]);
		puts("");
	}
	return 0;
}
