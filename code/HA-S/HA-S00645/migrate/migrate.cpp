#include<bits/stdc++.h>
using namespace std;
const int N=1.1e6;
#define ll long long
int n;
ll a[N],d,ans;
ll ver[N],Next[N],head[N],tot,dis[N],vis[N],cnt[N];
vector<int> to[20][20];
void dfs(int x,int t,int sum){
	if(x!=t)to[t][x].push_back(sum);
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d)dfs(i,t,sum+1);
	}
}
void solve(){
	ans=0;
	tot=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				to[i][j].clear();
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
			for(int j=i+1;j<=n;j++){
				sort(to[i][j].begin(),to[i][j].end());
				for(int k=0;k<to[i][j].size();k++){
//					printf("%d %d %d\n",i,j,to[i][j][k]);
				}
				if(to[i][j].size()>=2&&to[i][j][0]==to[i][j][1]&&to[i][j][1]!=to[i][j][2])ans++;
			}
		}
		printf("%lld\n",ans);
		return;
	}
	ll t=d/(a[2]-a[1]);
	if(t<2){
		printf("0\n");
		return;
	}
	printf("%lld\n",max((ll)0,n-2*t+1));
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

