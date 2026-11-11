#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
typedef long long ll;
const int N=2e6+5;
int C,T,n,vis[N];
ll m,a[N],res,sum[N];
void dfs(int rt){
	for(int i=1;i<=n;i++) vis[i]=0,sum[i]=0;
	vis[rt]=1,sum[rt]=1;
	queue<int> q;
	q.push(rt);
	int ans=0;
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		if(sum[rt]==2) ans++;
		for(int i=rt+1;i<=n;i++){
			if(a[i]-a[rt]<=m){
				if(vis[i]==0){
					vis[i]=vis[rt]+1;
					sum[i]=sum[rt];
					q.push(i);
				}else if(vis[i]==vis[rt]+1) sum[i]+=sum[rt];
			}
		}
	}
	res+=ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	I C >> T;
	while(T--){
		res=0;
		I n >> m;
		for(int i=1;i<=n;i++) I a[i];
		for(int i=1;i<=n;i++) dfs(i);
		O res << "\n";
	}
	return 0;
}
