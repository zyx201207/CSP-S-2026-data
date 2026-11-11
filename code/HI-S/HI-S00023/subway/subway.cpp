#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5*1e5+5;
int n,m,c,d,ask,a[N];
struct subway{
	vector<int> a,t; int k;
}sub[N];

long long vis[M];bool used[M];
struct node{
	int x;long long d;
	bool operator>(const node& other)const{
		return d>other.d;
	}
};
vector<node> g[M];
priority_queue<node,vector<node>,greater<node>> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>ask;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		sub[i].k=k;
		sub[i].a.resize(k+1);
		sub[i].t.resize(k+1);
		for(int j=1;j<=k;j++){
			cin>>sub[i].a[j]>>sub[i].t[j];
			g[sub[i].a[j]].push_back({i,sub[i].t[j]}); 
		} 
	}
	while(ask--){
		int s,e;
		cin>>s>>e;
		for(int i=1;i<=m;i++){
			vis[i]=-1;
			used[i]=false;
		}
		while(!q.empty()) q.pop();
		vis[s]=0;
		q.push({s,0});
		while(!q.empty()){
			node cur=q.top();q.pop();
			int x=cur.x;long long d=cur.d;
			if(used[x]) continue;
			used[x]=true;
			if(x==e){
				cout<<d+a[s]+a[e]<<"\n";
				break;
			}
			for(node i:g[x]){
				for(int j=1;j<=sub[i.x].k;j++){
					if(sub[i.x].a[j]==x) continue;
					int nx=sub[i.x].a[j];
					int nd=d+i.d+sub[i.x].t[j];
					if(vis[nx]==-1){
						q.push({nx,nd});
						vis[nx]=nd;
					}
				}
			}
		}
	} 
	return 0;
}
