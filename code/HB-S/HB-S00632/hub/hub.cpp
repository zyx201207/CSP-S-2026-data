#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> mp[105]; 
int br[100];
int bok[105];
int bk[100];
int d[105];
int ct=0,minn=0x3f3f3f3f;
int n,k;
queue<int> q;
void dfs(int nw){
	for(auto v:mp[nw]){
		if(bok[v]==1||br[v]==0)continue;
		bok[v]=1;
		dfs(v);
	}
}
int bfs(int st){
	q.push(st);
	bk[st]=1;
	while(!q.empty()){
		int nw=q.front();
		q.pop();
		for(auto v:mp[nw]){
			if(bk[v])continue;
			d[v]=d[nw]+1;
			bk[v]=1;
			q.push(v);
		}
	}
	int minnn=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(br[i]){
			minnn=min(minnn,d[i]);
		}
	}
	//cout<<minnn<<endl;
	return minnn;
}
void mj(int nw){
	if(nw==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=br[i];
		}
		if(cnt!=k){
			//cout<<222222<<endl;
			return ;
		}
		ct=0;
		for(int i=1;i<=n;i++){
			if(!bok[i]&&br[i]){
				dfs(i);
				ct++;
			}
		}
		if(ct>2){
			//cout<<222222<<endl;
			return ;
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,bfs(i));
			for(int j=1;j<=n;j++){
				d[j]=0;
				bk[j]=0;
				bok[i]=0;
			}
		}
		//cout<<maxn<<endl;
		minn=min(maxn,minn);
		return;
	}
	br[nw]=1;
	mj(nw+1);
	br[nw]=0;
	mj(nw+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		mj(1);
		for(int i=1;i<=n;i++)mp[i].clear();
		cout<<minn<<endl;
		minn=0x3f3f3f3f;
	}
	return 0;
}
