#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX/5;
int n,m;
int a[2000005];
int w[2000005][2],head,tail;
int d[3][2000005];
void zy(int x,int z){
	for(int j=0;j<=2;j++){
		if(d[j][x]>=z+1){
			for(int k=2;k>j;k--) d[k][x]=d[k-1][x];
			d[j][x]=z+1;
			if(j==0){
					
				w[++tail][0]=x; w[tail][1]=z+1;
			}
			break;
		}
	}
}
void bfs(int s){
	for(int i=1;i<=n;i++)
	for(int j=0;j<=2;j++) d[j][i]=inf;
	head=0,tail=1; w[1][0]=s,w[1][1]=0; d[0][1]=0;
	while(head<tail){
		head++; int x=w[head][0],z=w[head][1];
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]>m) break;
			zy(i,z);
		}
		for(int i=x-1;i>=1;i--){
			if(a[x]-a[i]>m) break;
			zy(i,z);
		}
	}
}
void solve(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;
			if(d[0][j]==d[1][j]&&d[2][j]>d[1][j]) ans++;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T; scanf("%lld%lld",&cid,&T);
	while(T--) solve();
	return 0;
}
