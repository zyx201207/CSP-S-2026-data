#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qs;
int w[500005];
int num[505];
int a[505][500005];
int s[100005];
int e[100005];
int ttt;
struct node{
	int l,nxt;
};
struct cc{
	int l,p,d;
};
vector<node>v[100005];
queue<cc>q;
int dis[100005];
int bfs(int start,int end){
	while(q.size())q.pop();
	q.push({-1,start,0});
	while(q.size()){
		cc now=q.front();
		q.pop();
		int l=now.l;
		int p=now.p;
		int d=now.d;
		if(p==end)return d;
		for(int i=0;i<v[p].size();i++){
			node g=v[p][i];
			int nl=g.l;
			int np=g.nxt;
			int new_dis=(l==nl)?d:(d+ttt*2);
			if(dis[np]>new_dis){
				dis[np]=new_dis;
				q.push({nl,np,dis[np]});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>num[i];
		int las=0;
		for(int j=1;j<=num[i];j++){
			cin>>a[i][j]>>ttt;
			if(j!=1){
				v[las].push_back({i,a[i][j]});
				v[a[i][j]].push_back({i,las});
			}
			las=a[i][j];
		}
	}
	for(int i=1;i<=qs;i++){
		memset(dis,0x3f,sizeof(dis));
		cin>>s[i]>>e[i];
		cout<<bfs(s[i],e[i])-ttt+w[s[i]]+w[e[i]]<<"\n";
	}
}
