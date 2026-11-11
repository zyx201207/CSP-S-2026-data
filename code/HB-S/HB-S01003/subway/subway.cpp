#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+505;
struct edg{
	int to,w,nxt;
}e[N*2];
int head[N];
int top=0;
void add(int u,int v,int w){
	e[++top]={v,w,head[u]};
	head[u]=top;
	e[++top]={u,w,head[v]};
	head[v]=top;
}
int cost[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cost[i];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int x,y;
			cin>>x>>y;
			add(m+i,x,y);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		int ans=0;
		cin>>x>>y;
		ans=cost[x]+cost[y];
		queue<int> q;
		vector<int> t(n+m+1,1e9);
		t[x]=0;
 		q.push(x);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i!=0;i=e[i].nxt){
				int w=e[i].w;
				int v=e[i].to;
				if(t[v]>t[u]+w){
					t[v]=t[u]+w;
					q.push(v);
				}
			}
		}
		cout<<ans+t[y]<<"\n";
	}
	return 0;
}
