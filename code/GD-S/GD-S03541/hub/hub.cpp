#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,k,fa[1000005],cnt,ans;
bool f[1000005];
vector<vector<int>>g;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
	cnt=k;
}
inline int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x),y=get(y);
	if(x!=y){
		fa[y]=x,cnt--;
	}
}
int spfa(int s,vector<vector<int>>&g,vector<int>&e){
	vector<int>dis(n+5,0x3f3f3f3f3f3f3f3f),cnt(n+5,0);
	vector<bool>vis(n+5,0);
	queue<int>q;
	q.push(s);
	vis[s]=1,dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto &v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1,cnt[v]++;
				if(!vis[v]){
					q.push(v
					);
					vis[v]=1;
				}
			}
		}
	}
	int res=INT_MAX;
	for(auto &v:e){
		res=min(res,dis[v]);
	}
	return res;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		vector<vector<int>>g(n+1,vector<int>());
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
//		for(int i=0;i<(1<<k);i++){
//			int lst=0;
//			init();
//			vector<int>e;
//			for(int j=0;j<k;j++){
//				if((i>>j)&1){
//					if(!lst){
//						lst=j;
//					}else{
//						merge(j,lst);
//						lst=j;
//					}
//					e.push_back(j);
//					f[j]=1;
//				}
//			}
//			if(cnt>=2)continue;
//			int res=0;
//			for(int j=1;j<=n;j++){
//				if(f[j])continue;
//				res=max(ans,spfa(j,g,e));
//			}
//			ans=max(ans,res);
//		}
		cout<<k-1<<endl;
	}
	return 0;
} 
