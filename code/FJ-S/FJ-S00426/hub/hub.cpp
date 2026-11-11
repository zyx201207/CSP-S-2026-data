#include<bits/stdc++.h>
using namespace std;
bool a[20005][20005];
long long n,k;
int s[20005];
int d[20005];
int vis[20005];
struct node{
	int m,l;
};
int ans=1e9;
void dfs(int id,int ss){
	if(ss>2){
		return;
	}
	if(id==k+1){
		queue<node> q;
		for(int i=1;i<=n;i++){
			d[i]=0;
		}
		for(int i=1;i<=k;i++){
			d[s[i]]=-1;
			q.push({s[i],0});
		}
		while(q.size()){
			node now=q.front();
			q.pop();
			for(int i=1;i<=n;i++){
				if(a[i][now.m]&&d[i]==0){
					q.push({i,now.l+1});
					d[i]=now.l+1;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(d[i]!=-1){
				sum=max(sum,d[i]);
			}
		}
		if(sum==1){
			for(int i=1;i<=k;i++){
				cout<<s[i]<<" ";
			}
			cout<<endl;
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=s[id-1]+1;i<=n;i++){
		if(vis[i])continue;
		int sss=ss+1;
		for(int j=1;j<id;j++){
			if(a[i][s[j]]){
				sss--;
			}
		}
			s[id]=i;
			vis[i]=1;
			dfs(id+1,sss);
			vis[i]=0;
			s[id]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
			d[i]=0;
			s[i]=0;
			vis[i]=0;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
