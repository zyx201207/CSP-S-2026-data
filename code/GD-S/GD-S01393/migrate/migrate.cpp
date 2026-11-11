#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[301][301],m,x[5001],cnt[301][301],vis[5001],ccnt[5001];
vector<int> e[5001];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&abs(x[i]-x[j])<=m){
				f[i][j]=1;
				cnt[i][j]=1;
			}
			else f[i][j]=-1,cnt[i][j]=0;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k)continue;
				if(f[j][i]!=-1&&f[i][k]!=-1&&(f[j][k]>f[j][i]+f[i][k]||f[j][k]==-1)){
					f[j][k]=f[j][i]+f[i][k];
					cnt[j][k]=cnt[j][i]*cnt[i][k];
				}
				else if(f[j][i]!=-1&&f[i][k]!=-1&&f[j][k]==f[j][i]+f[i][k]){
					cnt[j][k]+=cnt[j][i]*cnt[i][k];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&abs(x[i]-x[j])<=m){
				e[i].push_back(j);
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		queue<pair<int,int> >q;
		fill(vis+1,vis+1+n,-1);
		fill(ccnt+1,ccnt+1+n,0);
		q.push({i,0});
		vis[i]=0;
		while(!q.empty()){
			int now=q.front().first,w=q.front().second;q.pop();
			for(int v:e[now]){
//				cout<<v<<endl;
				if(vis[v]==-1){
					vis[v]=w+1,ccnt[v]=1,q.push({v,w+1});
//					cout<<now<<" -> "<<v<<endl;
				}
				else if(vis[v]==w+1){
//					cout<<now<<"->"<<v<<endl;
					ccnt[v]++;
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			ans+=(ccnt[j]==2);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	if( c<=7)while(t--)solve();
	if(c>7)while(t--) solve1();
}
