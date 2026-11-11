#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
struct node{
	ll a,b;
};
ll C,n,m,d,q,h[N],w[N],t[N][210],dis[N],c[N];
vector<node> v[N];

void dfs(int x,int s){
	for(int i=0;i<v[x].size();i++){
		int a=v[x][i].a,b=v[x][i].b;
		if(b==s){
			if(dis[a]>dis[x]){
				dis[a]=dis[x];
				c[a]=min(c[a],dis[a]+t[a][b]+w[a]);
				dfs(a,s);
			}
		}else if(s==-1){
			if(dis[a]>dis[x]+w[x]+t[x][b]){
				dis[a]=dis[x]+w[x]+t[x][b];
				c[a]=min(c[a],dis[a]+t[a][b]+w[a]);
				dfs(a,b);
			}
		}else{
			if(dis[a]>dis[x]+t[x][s]+t[x][b]){
				dis[a]=dis[x]+t[x][s]+t[x][b];
				c[a]=min(c[a],dis[a]+t[a][b]+w[a]);
				dfs(a,b);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>h[j];cin>>t[h[j]][i];
		}
		for(int a=1;a<=k;a++)
			for(int b=a+1;b<=k;b++){
				v[h[a]].push_back({h[b],i});
				v[h[b]].push_back({h[a],i});
			}
	}
	while(q--){
		memset(dis,127,sizeof(dis));
		memset(c,127,sizeof(c));
		int x,y;cin>>x>>y;dis[x]=c[x]=0;
		dfs(x,-1);
		cout<<c[y]<<endl;
	}
	return 0;
}
