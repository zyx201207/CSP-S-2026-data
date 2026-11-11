#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int N=505,M=5e5+10;
int c,n,m,d,q;
int s,e;
long long ans;
int w[M],k[N];

struct Node{
	int v,w;
};

vector<int> a[N],t[N];
vector<Node> b[M];
bool vis[N];
void dfs(int p,long long v){
	if(v>=ans)return;
	if(p==e){
		ans=min(ans,v);
		return;
	}
	for(int i=0;i<b[p].size();i++){
		Node ft=b[p][i];
		if(!vis[ft.v]){
			vis[ft.v]=1;
			dfs(ft.v,v+ft.w);
			vis[ft.v]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
		for(int j=1;j<=k[i];j++){
			for(int g=j+1;g<=k[i];g++){
				b[a[i][j-1]].push_back((Node){a[i][g-1],t[i][j-1]+t[i][g-1]});
			}
		}
	}
	for(int T=1;T<=q;T++){
		cin>>s>>e;
		ans=1000000005;
		memset(vis,0,sizeof(vis));
		vis[s]=1;
		dfs(s,0);
		cout<<ans+w[s]+w[e]<<endl;
	}
	return 0;
}
