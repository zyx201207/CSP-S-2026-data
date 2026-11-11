#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int c,n,m,d,qq,s,e,aa,tmp=0,dd,bb,cc,cnt;
int t[N],dis[N],vis[N],used[N],ans[N];
struct edge{
	int b,val,id;
};
struct node{
	int dot,val,id;
};
bool operator<(node a,node b){
	return a.val>b.val;
}
priority_queue<node> q;
vector<edge> v[N];
vector<int> min_dis[N];

void fun(){
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	for(int i=1;i<=m;i++){
		for(auto j:v[i]){
			if(j.b==s) q.push({s,j.val,-1});
		}
	}
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		if(vis[now.dot]) continue;
		vis[now.dot]=1;
		for(auto i:v[now.dot]){
			dis[i.b]+=v[i].val;
		}
	}
	for(int i=1;i<=m;i++){
		if(i!=s)min_dis[s].push_back(dis[i]+t[s]+t[i]);
		else min_dis[s].push_back(0);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&aa);
		tmp++;
		dd=aa;
		for(int j=1;j<=aa;j++){
		scanf("%d%d",&bb,&cc);
			v[dd].push_back({bb,cc,tmp});
			v[bb].push_back({dd,cc,tmp});
			dd=bb;
		}	
	}
	for(int i=1;i<=qq;i++){
		cnt=0;
		scanf("%d%d",&s,&e);
		if(!used[s]){
			fun();
			used[s]=1;
		} 
		for(int i:min_dis[s]){
			cout<<i<<endl;
			cnt++;
			if(cnt==e) printf("%d\n",i);
		}
	}
	return 0;
}
