#include<iostream>
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=6e5+5;
struct node{
	int u,v,w;
	bool operator<(const node &a) const{
		return w>a.w;
	}
};
struct ask{
	int x,y,idx;
};
vector<ask> as[N];
ull ans[N];
ull c,m,n,d,q;
ull w[N];
vector <node> e[N];
ull dis[N];
inline ull read(){
	int ans=0,f=1;
	char c;
	c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	} 
	while(c>='0' and c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	} 
	return ans*f;
}
void work(int x){
	priority_queue<node> q;
	q.push({x,x,0});
	while(q.size()){
		node tmp=q.top();
		q.pop();
		for(int k=0;k<e[tmp.v].size();k++){
			node i=e[tmp.v][k];
			if(dis[i.v] > dis[i.u]+i.w){
				dis[i.v]=dis[i.u]+i.w;
				q.push(i);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		w[i]=read();
	} 
	for(int i=1;i<=n;i++){
		int num; num=read();
		for(int j=1;j<=num;j++){
			int a,t; a=read(); t=read();
			e[a].push_back({a,m+i,t});
			e[m+i].push_back({m+i,a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy;
		xx=read(); yy=read();
		as[min(xx,yy)].push_back({min(xx,yy),max(yy,xx),i});
	}
	for(int i=1;i<=m;i++){
		if(as[i].empty()){
			continue;
		}
		memset(dis,0x3f3f3f,sizeof(dis));
		dis[i]=0;
		work(i);
		for(int j=0;j<as[i].size();j++){
			ans[as[i][j].idx]=w[as[i][j].x]+w[as[i][j].y]+dis[as[i][j].y]+dis[as[i][j].x];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}

