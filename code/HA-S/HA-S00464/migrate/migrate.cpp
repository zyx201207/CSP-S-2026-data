#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
ll readll(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}

const int N=2000006;

int n;
ll d,a[N];
struct node{
	int to,nxt;
}edg[N];
int cnt_edg,h[N];
void add(int u,int v){
	edg[++cnt_edg]={v,h[u]};
	h[u]=cnt_edg;
}
int dis[5005][5005];
int dp[5005][5005];
int rt;
void dfs(int x,int disP){
	if(dis[rt][x]<disP)return;
	if(dis[rt][x]>disP){
		dis[rt][x]=disP;
		dp[rt][x]=1;
	}else{
		dp[rt][x]++;
	}
	for(int i=h[x];i;i=edg[i].nxt){
		int y=edg[i].to;
		dfs(y,disP+1);
	}
}
void solve(){
	n=read();d=readll();
	for(int i=1;i<=n;i++){
		a[i]=readll();
	}
	bool flagA=1;
	for(int i=3;i<=n;i++){
		flagA&=(a[i]-a[i-1]==a[2]-a[1]);
	}
	if(flagA){
		ll t=d/(a[2]-a[1]);
		if(t<=1){
			printf("0\n");
			return;
		}
		ll ans=n-2*t+1;
		printf("%lld\n",max(0ll,ans));
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				add(i,j);
			}else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9;
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		rt=i;
		dfs(i,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]==2)++ans;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=cnt_edg;i++)edg[i]={0,0};
	for(int i=1;i<=n;i++)h[i]=0;
	cnt_edg=0;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
