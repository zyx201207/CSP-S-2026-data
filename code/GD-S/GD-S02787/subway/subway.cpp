#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
vector<int>a[4005];
vector<int>ra[4005];
vector<int>t[4005];
int mn=1e9;
bool vis[4005];
int y;
void dfs(int x/*,int cnt*/){
	if(x==y){
		//mn=min(mn,cnt+w[x]);
		cout<<1;
		return ;
	}
	
	vis[x]=1;
	for(int i:ra[x]){
		//cnt+=t[i][x];
		for(int j:a[i]){
			if(!vis[j]){
				
				dfs(j/*,cnt+w[x]+t[i][j]*/);
				vis[j]=0;
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	int T;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		
		for(int j=1;j<=2*k;j++){
			int o,p;
			cin>>o>>p;
			a[i].push_back(o);
			ra[o].push_back(i);
			t[i].push_back(p);
			
		} 
	}
	T=t[1][0];
	while(q--){
		int x;
		cin>>x>>y;
		mn=1e9;
		memset(vis,0,sizeof(vis));
		int cnt=0;
		
		cout<<T*2+w[x]+w[y]<<"\n";	
		
	} 
	return 0;
}
