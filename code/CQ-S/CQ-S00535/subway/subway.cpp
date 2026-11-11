#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
int w[N],k[N];
vector<int>op[N];
vector<vector<int>>a(N,vector<int>(N)),t(N,vector<int>(N));
int x,y;
int ans=1e9;
int f=0;
bool vis[N];
void dfs(int now,int sum){
	int f=0;
	for(int s=1;s<=op[now].size();s++){//遍历now的线路 
		if(vis[s]==0){
			vis[s]=1;
			sum+=t[now][s];
			for(int ss=1;ss<=op[y].size();ss++){
				if(s==ss){
					ans=min(ans,sum+t[s][y]);
					f=1;
				}
			}
			if(f==0){
				for(int i=1;i<=k[s];i++){
					int c=a[s][i];
					if(op[c].size()==1)continue;
					dfs(c,sum);
				}
			}
		}
	}
} 
void solve(){
	cin>>x>>y;
	memset(vis,0,sizeof vis);
	vis[x]=1;
	dfs(x,w[x]+w[y]);
	cout<<ans<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
			t[j][i]=t[i][j];
			op[a[i][j]].push_back(i);
		}
	}
	while(q--){
		solve();
	}
	return 0;
} 
