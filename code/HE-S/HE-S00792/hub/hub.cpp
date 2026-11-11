#include <bits/stdc++.h>
#define int  long long
using namespace std;
int C,T;
vector<int>a[110];
queue<pair<int,int> >p;
bool t[110],flag[110];
int n,k,ans;
queue<int>q;
void solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		t[i]=flag[i];
//		cout<<flag[i]<<" ";
	}
//	puts("");
	for(int i=1;i<=n;i++){
		if(!t[i]){
			if(cnt==2)return ;
			while(!q.empty())q.pop();
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				if(t[u])continue;
				t[u]=1;int len=a[u].size();
				for(int j=0;j<len;j++){
					int v=a[u][j];
					if(t[v])continue;
					q.push(v);
				}
			++cnt;
			}
		}
	}
	int sss=-1;
	for(int i=1;i<=n;i++){
		if(!flag[i])continue;
		memset(t,0,sizeof t);
		while(!p.empty())p.pop();
		p.push({i,0});
		while(!p.empty()){
			auto now=p.front();
			int u=now.first;
			p.pop();
			if(t[u])continue;
			t[u]=1;
			if(!flag[u]){sss=max(sss,now.second);continue;
			}
			int len=a[u].size();
			for(int j=0;j<len;j++){
				int v=a[u][j];
				if(t[v])continue;
				p.push({v,now.second+1});
			}
		}
//		cout<<i<<" "<<sss<<endl;
	}
	ans=min(ans,sss);
}
void dfs(int x,int sum){
	if(x==n+1){if(sum==k)solve();return ;}
	flag[x]=1;
	dfs(x+1,sum);
	flag[x]=0;
	dfs(x+1,sum+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;;
	while(T--){
		cin>>n>>k;
		memset(flag,0,sizeof flag);
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans=0x3f3f3f3f;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
