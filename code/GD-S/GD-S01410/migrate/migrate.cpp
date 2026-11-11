#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,cnt[N],ans=N;
int a[N];
bool vis[N];
void dfs(int x,int sz,int step){
	if(x==sz){
		cnt[step]++;
		ans=min(ans,step);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]) return ;
		if(a[i]-a[x]>d) return ;
		vis[i]=1;
		dfs(i,sz,step+1);
		vis[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int tot=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				memset(vis,0,sizeof vis);
				memset(cnt,0,sizeof cnt);
				ans=N;
				vis[u]=1;
				dfs(u,v,0);
				if(ans!=N&&cnt[ans]==2){
					tot++;
				}
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
