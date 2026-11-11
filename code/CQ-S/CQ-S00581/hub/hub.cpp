#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;

int c,T;
int n,k;
int ij,ans=inf;
struct h{
	int x,y,e;
}o[100005];
int fe[100005];
int v[100005];
int fa[100005];

void add(int sx,int sy){
	ij++;
	o[ij].x=sx;
	o[ij].y=sy;
	o[ij].e=fe[o[ij].x];
	fe[o[ij].x]=ij;
	return;
}

int gfa(int i){
	if(i==fa[i]){
		return i;
	}else{
		return fa[i]=gfa(fa[i]);
	}
}
void fo(int i,int j){
	i=gfa(i);
	j=gfa(j);
	if(i!=j){
		fa[i]=j;
	}
}

queue<int> q;
int s[100005];
void dfs(int u,int d){
	if(d>k)return;
	if(u>n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=2*n-2;i+=2){
			if(v[o[i].x]==1&&v[o[i].y]==1){
				fo(o[i].x,o[i].y);
			}
		}
		int dt=-1,dr=-1;
		for(int i=1;i<=n;i++){
			if(v[i]==0)continue;
			if(dt==-1)dt=gfa(i);
			else if(dt!=gfa(i)&&dr==-1)dr=gfa(i);
			else if(dt!=gfa(i)&&dr!=gfa(i))return;
		}
		for(int i=1;i<=n;i++){
			if(v[i]==1){
				s[i]=0;
				q.push(i);
			}else s[i]=inf;
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int j=fe[u];j;j=o[j].e){
				int nt=o[j].y;
				if(s[u]+1<s[nt]){
					q.push(nt);
					s[nt]=s[u]+1;
				}
			}
		}
		int pans=0;
		for(int i=1;i<=n;i++)pans=max(pans,s[i]);
		ans=min(ans,pans);
		return;
	}else{
		v[u]=0;
		dfs(u+1,d);
		v[u]=1;
		dfs(u+1,d+1);
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ij=0;
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			fe[i]=0;
			v[i]=0;
		}
		for(int i=1;i<=n-1;i++){
			int sx,sy;
			cin>>sx>>sy;
			add(sx,sy),add(sy,sx); 
		}
		
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
