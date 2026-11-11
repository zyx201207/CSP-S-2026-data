#include<bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;
const int N=2e6+5;
#define ll long long
#define pb push_back
ll X[N],ans,n,d,dis[N],cnt[N];
vector<int > E[N];
queue<int > q;
bool vis[N];
void bfs(int s){
	memset(dis,0,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	q.push(s); cnt[s]=1;
	while(!q.empty()){
		int p=q.front(); q.pop();
		for(int i=0;i<E[p].size();i++){
			int t=E[p][i];
			if(dis[t]==0){
				cnt[t]=cnt[p];
				dis[t]=dis[p]+1;
				q.push(t);
			}
			else if(dis[t]==dis[p]+1) cnt[t]+=cnt[p];
		}
	}
//	for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
//	cout<<endl;
	for(int i=s+1;i<=n;i++)
		ans+=(cnt[i]==2);
}
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T; cin>>c>>T;
	while(T--){
		ans=0; cin>>n>>d;
		for(int i=1;i<=n;i++) E[i].clear();
		for(int i=1;i<=n;i++) scanf("%lld",&X[i]);
//		cout<<"!!!"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(X[j]-X[i]>d) break;
//				cout<<j<<" "<<(X[j]-X[i])<<endl;
				E[i].pb(j);
			}
		}
		for(int i=1;i<=n;i++)
			bfs(i);
		cout<<ans<<endl;
	}
	return 0;
}