#include<bits/stdc++.h>
using namespace std;
long long arr[5005],path[5005],cnt[5005];
vector<long long>G[5005];
int n;long long d,ans;
void solve(int start){
	memset(cnt,0,sizeof(cnt));
	memset(path,0x3f,sizeof(path));
	queue<int>q;path[start]=0;
	q.push(start);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<int(G[now].size());i++){
			int v=G[now][i];
			if(path[now]+1==path[v])cnt[v]++;
			if(path[now]+1>path[v]){
				continue;
			}
			path[v]=path[now]+1;
			cnt[v]++;
			q.push(v);
		}
	}
	for(int i=start+1;i<=n;i++){
		if(cnt[i]==3)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(arr[j]-arr[i])<=d){
					G[i].push_back(j),G[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)solve(i);
		printf("%lld\n",ans);
	}
	return 0;
}
