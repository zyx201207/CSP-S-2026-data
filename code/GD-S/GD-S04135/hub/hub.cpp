#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m,s;
vector<int>v[1000005];
bool vis[1000005],b[1000005];
void dfs(int x,int fa){
	vis[x]=1;
	for(auto i:v[x]){
		if(i!=fa&&b[i]) dfs(i,x);
	}
}
int dfs1(int x,int fa){
	if(b[x]) return 0;
	int s=INT_MAX;
	for(auto i:v[x]){
		if(i!=fa) s=min(dfs1(i,x)+1,s);
	}
	return s;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>t;
	while(t--){
		s=2e6;
		cin>>n>>k;m=(1<<n);
		for(int i=1,x,y;i<n;i++) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
		for(int i=0;i<m;i++){
			memset(vis,0,sizeof vis);
			memset(b,0,sizeof b);
			int h=0,ans=0,p=0;
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i) b[j]=1,p++;
			}
			if(p!=k) continue;
			for(int j=1;j<=n;j++){
				if(((1<<(j-1))&i)&&!vis[j]){
					dfs(j,0);
					h++;
				}
			}
			if(h!=2) continue;
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i) ;
				else ans=max(ans,dfs1(j,0));
			}
			s=min(s,ans);
		}
		cout<<s<<endl;
	}
}
