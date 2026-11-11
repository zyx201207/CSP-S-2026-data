#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
long long a[N];
int c,t,n,d;
bool vis[N],p[N];
bool bfs(int x,int y){
	queue<pair<int,int>> q;
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	q.push({x,0});
	int sum=0,cs=0;
	while(!q.empty()){
		int u=q.front().first;
		q.pop();
		int r=q.front().second;
		if(cs<r&&cs!=0)continue;
		for(int i=1;i<=d;i++){
			if(p[u+i]&&vis[u+i]==0&&u+i<y){
				q.push({u+i,r});
				vis[u+i]=1;
			}
			else if(u+i==y){
				sum++;
				cs=q.front().second;
				if(sum>2)return 0;
			}
		}
	}
	if(sum==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[a[i]]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)break;
				if(bfs(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
} 
