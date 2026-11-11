#include<bits/stdc++.h>
using namespace std;
//¹Ø×¢luogu 1406766 Ð»Ð»ß÷ 
const int N=30;
int c,T,n,m,a[N][N],ans;
int cs[N],fa[N],vis[N],vis2[N];
vector<int> v[N];
void fun(int x,int fat){
	if(vis[x]){
		if(vis[fat])fa[x]=fa[fat];
		else fa[x]=x;
	}else fa[x]=0;
	for(int i:v[x]){
		if(i==fat)continue;
		fun(i,x);
	}
}
bool check(){
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)vis[cs[i]]=1;
	fun(1,0);
	int sum=0;
	for(int i=1;i<=m;i++){
		if(vis2[fa[cs[i]]]==0)vis2[fa[cs[i]]]=1,sum++;
	}
	if(sum<=2) return 1;
	else return 0;
}
void dfs(int x,int y){
	if(x>m&&check()){
		int cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)vis[cs[i]]=1;
//		for(int i=1;i<=m;i++)cout<<cs[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=n;i++){
			int minn=0x3f3f3f3f;
			if(vis[i])continue;
			for(int j=1;j<=m;j++){
				if(i!=cs[j])
				minn=min(minn,a[i][cs[j]]);
			}
			cnt=max(cnt,minn);
		}
		ans=min(ans,cnt);
	} 
	for(int i=y;i<=n;i++){
		cs[x]=i;
		dfs(x+1,i+1);	
	}
}

void solve1(){
	cin>>n>>m;
	ans=0x3f3f3f3f;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)v[i].clear();
	//memset(fa,0,sizeof(fa));
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)a[i][j]=0;
				else a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	dfs(1,1);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c<=3)solve1();
	}
	return 0;
}
/*
0 2
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

0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/

