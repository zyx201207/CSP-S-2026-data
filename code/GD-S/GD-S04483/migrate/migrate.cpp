#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,t,n,ed,cnt,mn;
bool f;
long long d,a[N];
vector<int> g[N];
void dfs(int u,int s){
	if(u>ed) return;
	if(s>mn) return;
	if(u==ed){
		cnt++;
		mn=s;
		if(cnt>2) f=1;
		return;
	}
	for(int i=g[u].size()-1;i>=0;i--){
//		cout<<u<<"->"<<g[u][i]<<' '<<ed<<' '<<cnt<<'\n';
		dfs(g[u][i],s+1);
		if(f) return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) g[i].push_back(j);
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				ed=j;
				f=0;
				cnt=0;
				mn=1e9;
				dfs(i,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

