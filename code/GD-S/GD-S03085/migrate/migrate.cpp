#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10,M=2e6;
long long c,t,n,d,ans,x[M],dis[N][N],num[N][N],v[N][N],len[N];
queue<long long>q;
void bfs(long long s){
	for (long long i=1;i<=n;i++){
		dis[s][i]=1e9;
		num[s][i]=0;
	}
	q.push(s);
	dis[s][s]=0;num[s][s]=1;
	while(!q.empty()){
		long long now=q.front();
		q.pop();
		for (long long i=1;i<=len[now];i++){
			long long nxt=v[now][i];
			if (dis[s][nxt]==dis[s][now]+1){
				num[s][nxt]+=num[s][now];
			}
			if (dis[s][nxt]==1e9){
				dis[s][nxt]=dis[s][now]+1;
				num[s][nxt]=num[s][now];
				q.push(nxt);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--){
		ans=0;
		cin >>n>>d;
		for (long long i=1;i<=n;i++){
			cin >>x[i];len[i]=0;
		}
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				if (i==j)continue;
				if (abs(x[i]-x[j])<=d){
					len[i]++;
					v[i][len[i]]=j;
				}
			}
		}
		for (long long i=1;i<=n;i++){
			bfs(i);
		}
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				if (i==j)continue;
				if (num[i][j]==2){
					ans++;
				}
			}
		}
		cout <<ans/2<<'\n';
	}
	return 0;
}
