#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int c,t,n,k,x,y,vis[N],vis2[N],d[N],ans;
vector<int>a[N];
void dfs(int k){
	int l=a[k].size();
	for(int i=0;i<l;i++){
		int v=a[k][i];
		if(d[v]<d[k]+1)continue; 
		d[v]=d[k]+1;
		dfs(v);
	}
} 
void dfs(int k,int t,int t2){
	if(!t){
		memset(vis2,0,sizeof(vis2));
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++){
			vis2[i]=vis[i];
			if(vis[i])d[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				dfs(i);
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,d[i]);
		ans=min(ans,maxn);
	}
	if(k>n)return;
	if(n-k+1<t)return;
	dfs(k+1,t,t2);
	int l=a[k].size(),flag=1;
	for(int i=0;i<l;i++){
		int v=a[k][i];
		if(vis[v]){
			flag=0;
			break;
		}
	}
	if(flag&&!t2)return;
	vis[k]=1;
	dfs(k+1,t-1,t2-flag);
	vis[k]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		ans=1e9;
		dfs(1,k,2);
		cout<<ans<<endl;
	}
	return 0;
}
