#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int C,T;
int n,m,ans,sss,dd[100005];
bool d2[100005];
vector<int> k[100005];
bool bk[1005];
bool vis[1005];
int a[1005][1005],use[1005];
int jis(){
	
	int res=0;
	for(int i=1;i<=n;i++){
		int s=INF;
		for(int j=1;j<=n;j++)if(bk[j])s=min(s,a[i][j]);
		res=max(res,s);
	}
	return res;
}
void dfs(int x,int s,bool f){
//	cout<<x<<" "<<s<<" "<<f<<"\n";
	if(s==m){
		ans=min(ans,jis());
		return;
	}
	if(x>n)return; 
	dfs(x+1,s,f);
	bool flag=0;
	for(int i=1;i<=s;i++){
		if(a[x][use[i]]==1){
			flag=1;
			break;
		}
	}
//	for(int i=1;i<=n;i++)cout<<use[i]<<" ";
//	cout<<"\n";
	if(s==0||flag)use[s+1]=x,bk[x]=1,dfs(x+1,s+1,f),bk[x]=0;
	else if(f)use[s+1]=x,bk[x]=1,dfs(x+1,s+1,0),bk[x]=0;
}
void ddfs(int r,int x,int s){
	vis[x]=1,a[r][x]=s;
	for(int i=0;i<k[x].size();i++)if(!vis[k[x][i]])ddfs(r,k[x][i],s+1);
}
void work(){
	int ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int s=0;
			for(int k=1;k<=n;k++)s=max(s,min(a[k][j],a[i][j]));
			ans=min(ans,s);
		}
	}
	cout<<ans-(m-2)<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)k[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			k[x].push_back(y);k[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			ddfs(i,i,0);
		}
		if(C>=4){
			work();
			continue;
		}
		ans=INF;
		dfs(1,0,1);
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
4 1
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
