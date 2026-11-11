#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=1e6+5;
int c,t,n,k,ans;
vector<int>e[N];
bool f[N];
int dis(int k,int fa){
	if(f[k]) return 0;
	int ans=INF;
	for(int s:e[k])
		if(s!=fa) ans=min(ans,dis(s,k)+1);
	return ans;
}
void dfs(int i,int cnt,int lt){
	if(n-i+1<cnt) return ;
	if(i>n){
		int mx=0;
		for(int j=1;j<=n;j++){
			if(f[j]) continue;
			mx=max(mx,dis(j,-1));
		}
		ans=min(ans,mx);
		return ;
	}
	dfs(i+1,cnt,lt);
	if(cnt>0){
		int flag=1;
		for(auto s:e[i])
			if(f[s]){
				flag=0;
				break;
			}
		if(lt+flag>2) return;
		f[i]=1;
		dfs(i+1,cnt-1,lt+flag);
		f[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>t;
	while(t--){
		ans=INF;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u); 
		}
		dfs(1,k,0);
		cout<<ans<<endl;
	}
	return 0;
}
