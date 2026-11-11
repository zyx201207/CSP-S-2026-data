#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,m,n,d,q;
long long ans;
int w[maxn];
bool vis[maxn];
vector<pair<int,long long> > a_tim[maxn];//站到线
vector<pair<int,long long> > b_tim[maxn];//线到站
struct node{
	int root;long long tim;
	bool operator<(const node & aaa)const{
		return aaa.tim<tim;
	}
};
inline int readint(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long dis(int x,int y){
	long long ans=LLONG_MAX;
	priority_queue<node> q;
	memset(vis,0,sizeof vis);
	q.push(node{x,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.root==y)ans=min(ans,t.tim);
		if(vis[t.root])continue;
		vis[t.root]=1;
		for(auto i:a_tim[t.root]){
			long long tima=i.second;
			for(auto j:b_tim[i.first]){
				if(t.root==j.first)continue;
				q.push(node{j.first,t.tim+tima+j.second});
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=readint();n=readint();
	m=readint();d=readint();
	q=readint();
	for(int i=1;i<=m;i++){w[i]=readint();}
//	cin>>c>>m>>n>>d>>q;
//	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int t;t=readint();
		for(int j=1;j<=t;j++){
			int sub,tim;sub=readint(),tim=readint();
			a_tim[sub].push_back(make_pair(i,tim));
			b_tim[i].push_back(make_pair(sub,tim));
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;x=readint(),y=readint();
		int ans=w[x]+w[y];
		cout<<dis(x,y)+ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
 
*/

