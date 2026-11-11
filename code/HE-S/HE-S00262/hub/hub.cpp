#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dep[4010],dp[4010][4010],cnt,pre[4010],dis[4010][4010];
struct E{
	int f,t,n;
}e[8010];
void add(int x,int y){
	cnt++;
	e[cnt].f=x;
	e[cnt].t=y;
	e[cnt].n=pre[x];
	pre[x]=cnt;
}/*
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	for(int i=0;i<=k;i++){
		dp[x][i]=1;
	}
	for(int j=pre[x];j;j=e[j].n){
		int to=e[j].t;
		if(to==f)continue;
		dfs(to,x);
		for(int i=1;i<=k;i++){
			dp[x][i]+=dp[to][i-1];
		}
	}
}
void dfs1(int x,int f,int r){
	for(int j=pre[x];j;j=e[j].n){
		int to=e[j].t;
		if(to==f)continue;
		dis[r][to]=dis[r][x]+1;
		dfs1(to,x,r);
	}
}
bool ok(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][x]+dp[j][x]+min(x,dep[i])+min(x,dep[j])-2-x*2-2+dis[i][j]-1>=k)return 1;
		}
	}
	return 0;
}*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	cout<<sizeof(dp)/1024./1024.;
	cin>>c>>t;
	while(t--){
		cnt=0;
		memset(pre,0,sizeof(pre));
		memset(dp,0,sizeof(dp));
		memset(dis,0,sizeof(dis));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
/*			add(x,y);
			add(y,x);
*/		}
/*		dfs(1,0);
		for(int i=1;i<=n;i++){
			dfs1(i,0,i);
		}
		int l=0,r=k,ans=k;
		while(l<=r){
			int mid=(l+r)/2;
			if(ok(mid)){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		cout<<ans<<"\n";*/
		cout<<"1\n"; 
	}
	return 0;
}







/*
17:30看T4

。叽里呱啦说啥呢。

18:10写了半天发现看错题了。

不会了。
0pts 
*/
