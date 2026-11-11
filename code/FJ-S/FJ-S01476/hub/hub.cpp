#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=20000;
void in(int &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
int n,k,vis[N],f[N];
vector<int>edge[N];
void dfs(int u){
	f[u]=0;
	for(auto v:edge[u]){
		if(f[v]==n&&vis[v]){
			dfs(v);
		}
	}
}
void solve(int c){
	in(n);in(k);
	for(int i=1;i<n;i++){
		int u,v;
		in(u);in(v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	
	if(1){
		int aaa=n;
		for(int p=0;p<(1<<n);p++){
			int num=0,ans=0;
			for(int i=1;i<=n;i++) f[i]=n;
			for(int i=0;i<n;i++){
				vis[i+1]=((p>>i)&1);
				num+=vis[i+1];
			}
			if(num!=k) continue;
			int cnt=0;
			for(int i=1;i<=n;i++) {
				if(f[i]==n&&vis[i]){
					dfs(i);
					cnt++;
				}
			}
			if(cnt>2) continue;
			queue<int>q;
			for(int i=1;i<=n;i++)
				if(vis[i]) q.push(i);
			while(!q.empty()){
				int h=q.front();
				for(int i:edge[h]){
					if(f[i]>f[h]+1){
						if(f[i]==n) q.push(i);
						f[i]=f[h]+1;
					}
				}
				q.pop();
			}
			for(int i=1;i<=n;i++) ans=max(ans,f[i]);
			aaa=min(aaa,ans);
		}
		printf("%d\n",aaa);
	}
	
	for(int i=1;i<=n;i++) edge[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	in(c);
	in(t);
	while(t--) solve(c);
	return 0;
}
