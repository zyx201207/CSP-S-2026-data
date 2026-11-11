#include <bits/stdc++.h>//O(n^3),30pts
using namespace std;
#define int long long
int c,t,n,d,x[5010];
pair<int,int> ways[5010][5010];//length,number
void dfs(int st,int now,int step){
	if(ways[st][now].first>step){
		ways[st][now].first=step;
		ways[st][now].second=1;
	}
	else if(ways[st][now].first==step) ways[st][now].second++;
	int pos=upper_bound(x+1,x+n+1,x[now]+d)-x;
	if(x[pos]<=x[now]) pos=n;
	else pos--;
	for(int i=now+1;i<=pos;i++) dfs(st,i,step+1);
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				ways[i][j].first=9e18;
				ways[i][j].second=0;
			}
		for(int i=1;i<=n;i++) dfs(i,i,0);
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(ways[i][j].first<9e18&&ways[i][j].second==2) cnt++;
				//cout<<ways[i][j].first<<' ';//debug
			}
			//cout<<endl;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}/*example1
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/