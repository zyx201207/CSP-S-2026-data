#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=505;
struct node{
	int id;
	ll d;
	friend bool operator<(node x,node y){
		return x.d<y.d;
	}friend bool operator>(node x,node y){
		return x.d>y.d;
	}
}qs[N];
bool c;
int n,m,d,q,w[2*N+M],k,a,t,p,vis[M+2*N];
ll ans[2*N+N];
vector<node> st[M+2*N];
priority_queue<node,vector<node>,greater<node> >f; 
ll dis(int x,int y){
	for(int i=1;i<=2*m+n;i++){
		ans[i]=5e14;
		vis[i]=0;
	}
	f.push({x,0});
	ans[x]=0;
	while(!f.empty()){
		int s=f.top().id;
		f.pop();
		if(vis[s])continue;
		vis[s]=1;
		for(int i=0;i<st[s].size();i++){
			node t=st[s][i];
			int id=t.id,d=t.d;
			if(!vis[id]&&d+ans[s]<ans[id]){
				ans[id]=d+ans[s];
				f.push({id,ans[id]});
			}
		}
	}return ans[y];
}
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		p=2*i-1;
		st[p].push_back({p+1,w[i]});
		st[p+1].push_back({p,w[i]});
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			p=2*m+i;
			st[p].push_back({2*a,t});
			st[2*a].push_back({p,t});
		}
	}int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<dis(2*x-1,2*y-1)<<"\n";
	}
	return 0;
}

