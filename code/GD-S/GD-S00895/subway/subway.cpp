#include<bits/stdc++.h>
using namespace std;
int n,m,num,ans[1000010],ccc,d,q,w[1000010],cnt[510],x[1000010],y[1000010];
bool c[500010];
struct Int{
	int g,gg;
};
vector<Int>a[500010];
void f(int k){ 
	memset(ans,0x3f, sizeof(ans));
	memset(c,0,sizeof(c));
	ans[k]=0;
	queue<int>q;
	q.push(k);
	c[k]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		c[u]=0;
		for(Int i:a[u]){
			int v=i.g,w=i.gg;
			if(c[v]==1)
			continue;
			if(ans[v]>ans[u]+w){
				ans[v]=ans[u]+w;
				if(!c[v]){
				q.push(v);
				c[v]=1;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		cin>>cnt[i];
		for(int j=1; j<=cnt[i]; j++){
			cin>>x[i]>>y[i];
			a[x[1]].push_back({x[2],y[1]});
			a[x[2]].push_back({x[1],y[2]});
		}
	}
	for(int i=1; i<=q; i++){
		cin>>x[i]>>y[i];
		f(x[i]);
		cout<<w[x[i]]+w[y[i]]+ans[y[i]]<<"\n";
	}
	return 0;
} 
