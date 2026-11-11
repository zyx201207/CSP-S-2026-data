#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5010;
int c,t,tot;
		int n,d;
int cnt[N][N],dp[N][N];
int head[N],a[N],din[N];
struct node{
	int to,next;
}e[25000010];
void add(int x,int y){
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot++;
	din[y]++;
}
void solve(int now){
	
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(din[i]==0){
			q.push(i);
			dp[now][i]=0;
			cnt[now][i]=0;
		}
	}
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].next){
			int y=e[i].to;
			if(dp[now][x]+1<dp[now][y]){
				dp[now][y]=dp[now][x]+1;
				cnt[now][y]=1;
			}
			else if(dp[now][x]+1==dp[now][y]){
				cnt[now][y]++;
			}
			if(--din[y]==0){
				q.push(y);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[now][i]<<" "<<cnt[now][i]<<endl;
//	}
}
void solve1(int now){
	memset(head,-1,sizeof head);
	memset(din,0,sizeof din);
	tot=0;
	for(int i=now;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				add(i,j);
			}
			else break;
		}
	}
	solve(now);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dp,0x3f,sizeof dp);
		memset(cnt,0,sizeof cnt);
		tot=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++) solve1(i);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//					cout<<cnt[i][j]<<" ";
				if(cnt[i][j]==2){
					ans++;
				}
			}
//			cout<<endl;
		}
		cout<<ans<<endl; 
	}
	
	return 0;
}
/*
0 2
4 2 
1 2 3 4
5 2
1 2 3 4 5

一个点到另一个点的最短路径数量恰好为 2
则这个点对做出贡献
有多少点对做出贡献

求出 1 到所有点的最短路径 dp[i] 数量 
 l ,r 最短路径  即 dp[r]-dp[l];

*/
