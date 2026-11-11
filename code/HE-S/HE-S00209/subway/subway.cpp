#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q,w[505],a[505][N],t[505][N],go_plan[100005][5],ans,x[N],now_;
void dfs(long long pos,long long pl_start,long long plan_end){
	if(pos>n){
		if(now_==plan_end){
			ans+=w[plan_end];
		}
		return ;
	}
	for(long long i=1;i<=x[pos];i++){
		ans+=t[pos][i];
		dfs(pos+1,pl_start,plan_end);
		ans-=t[pos][i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long j=1;j<=n;j++){
		cin>>x[j];
		for(long long i=1;i<=x[j];i++){
			cin>>a[j][i]>>t[j][i];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>go_plan[i][1]>>go_plan[i][2];
		ans=w[go_plan[i][1]];
		now_=go_plan[i][1];
		dfs(1,go_plan[i][1],go_plan[i][2]);
		cout<<ans<<'\n';
	}
	return 0;
}
