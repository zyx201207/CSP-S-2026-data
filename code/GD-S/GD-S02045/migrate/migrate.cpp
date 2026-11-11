#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e3+10;
const int inf=1e18;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
inline void print(int x){
	if(x<10){putchar(x+'0');return;}
	print(x/10);putchar(x%10+'0');
}
int x[maxn],n,d;
int dis[maxn][maxn],cnt[maxn][maxn];
void dfs(int now,int id){
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]>d)return;
		if(dis[id][i]<dis[id][now]+1)return;
		if(dis[id][i]>dis[id][now]+1){
			dis[id][i]=dis[id][now]+1;
			cnt[id][i]=1;
		}else if(dis[id][i]==dis[id][now]+1)cnt[id][i]++;
		dfs(i,id);
	}
}
void solve(){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	n=read(),d=read();
	int ans=0;
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)dfs(i,i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	print(ans);putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
}
