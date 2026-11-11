#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000010];
int dist[1010][1010];
int cnt[1010][1001];
int f[1010][1010];
void dfs(int x,int step,int en,int p){
	if(cnt[p][en]>2) return;
	if(x==en&&step==dist[p][en]){
		cnt[p][en]++;
		return;
	}
	if(step==dist[p][en]) return;
	for(int i=x+1;i<=en;i++){
		if(a[i]-a[x]>d) break;
		else dfs(i,step+1,en,p);
	}
}
void solve(){
	scanf("%d%lld",&n,&d);
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int now=i,cnt=0;
			while(now<j){
				for(int k=now;k<=j;k++){
					if(a[k]-a[now]<=d&&(k==j||a[k+1]-a[now]>d)){
						now=k;
						cnt++;
						break;
					}
				}
			}
			dist[i][j]=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dfs(i,0,j,i);
			if(cnt[i][j]==2) ans++;
		}
	}
	printf("%d\n",ans);
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	cout<<t;
	while(t--){
		solve();
	}
	return 0;
}

