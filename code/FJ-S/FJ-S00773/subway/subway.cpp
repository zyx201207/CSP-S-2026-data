#include<bits/stdc++.h>
using namespace std; 
int c,n,d,q;
bool v[1000005][1000005];
long long m,b,e;
int a[2505][2505],w[1000005];
long long minn1,minn2;
void dfs(long long x,long long y,long long res){
	if(x==e&&y==e)return ;
	if(x<1||y<1||x>m||y>m||!v[x][y]||!a[x][y])return ;
	v[x][y]=true;
	minn1+=res;
	dfs(x+1,y,res+a[x+1][y]);
	dfs(x-1,y,res+a[x-1][y]);
	dfs(x,y-1,res+a[x][y-1]);
	dfs(x,y+1,res+a[x][y+1]);
}
void dfs1(long long x,long long y,long long res){
	if(x==e&&y==e)return ;
	if(x<1||y<1||x>m||y>m||!v[x][y]||!a[x][y])return ;
	v[x][y]=true;
	minn2+=res;
	dfs1(x+1,y,res+a[x+1][y]);
	dfs1(x-1,y,res+a[x-1][y]);
	dfs1(x,y-1,res+a[x][y-1]);
	dfs1(x,y+1,res+a[x][y+1]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long t,x;
			cin>>x>>t;
			a[i][x]=w[i]+w[x]+t;
			a[x][i]=w[i]+w[x]+t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b>>e;
		dfs(b,1,a[b][1]);
		dfs1(1,b,a[1][b]);
		cout<<min(minn1,minn2)<<endl;
	}
	return 0;
}
