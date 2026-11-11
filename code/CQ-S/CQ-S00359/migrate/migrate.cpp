#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int x=0,f=1; char h=getchar();
	while(!isdigit(h)){if(h=='-') f=-f; h=getchar();}
	while(isdigit(h)){x=(x<<3)+(x<<1)+(h^48); h=getchar();}
	return x*f;
}
const int N=2e6+10;
int n,d,a[N],diff[N],minn[N],cnt[N];
void dfs(int u,int sum,int tot){
	if(tot<minn[u]) minn[u]=tot,cnt[u]=1;
	else if(tot==minn[u]) cnt[u]++;
	if(u==n) return;
	if(sum+diff[u+1]<=d) dfs(u+1,sum+diff[u+1],tot);
	if(diff[u+1]<=d) dfs(u+1,diff[u+1],tot+1);
}
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read(),diff[i]=minn[i]=cnt[i]=0;
	for(int i=1;i<n;i++) diff[i]=a[i+1]-a[i];
	n--;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) minn[j]=n+1,cnt[j]=0;
		dfs(i,diff[i],1);
		for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
	}
	printf("%d\n",ans);
}
signed main(){
//	freopen("D:/csps-new/down/migrate/migrate2.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--) solve();
	return 0;
}
/*

*/
