#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> pii;
const int N=2e5+10;
int n,m,t;
int a[N];
ll ans=0;
vector<int> G[32];
void solve(int u){
	vector<int> G2;
	bool vis[N];
	int cnt=0;
	for(int v=0;v<G[u].size();v++){
		vis[G[u][v]]=1;
		cnt+=1;
		
	}
	bool nvis[N];
	for(int i=u-1;i>=0;i--){
		cnt=0;
		memset(nvis,0,sizeof nvis);
		for(int v=0;v<G[u].size();v++){
			if(vis[G[u][v]]==1){
				nvis[G[u][v]]=1;
				cnt+=1;
			}
			
		}
		for(int v=0;v<G[u].size();v++){
				vis[G[u][v]]=nvis[G[u][v]];
			}
		
		if(cnt<m){
			break;
		}
		G2.clear();
		for(int v=0;v<G[u].size();v++){
			G2.push_back(G[u][v]);
		}
	}
	ans=G2[0];
	for(int i=1;i<m;i++){
		ans&=G2[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++){
			
			if(a[i]&(1<<j)){
				G[j].push_back(a[i]);
			}
		}
	}
	for(int i=29;i>=0;i--){
		if(G[i].size()>=m){
			solve(i);
			break;
		}
	}
	cout<<ans;
}
