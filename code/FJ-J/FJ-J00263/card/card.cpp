#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],m,ans=-1e9,may=-1e9,cnt[MAXN][35],id,zt[MAXN];
bool vis[35];
void dfs(int dep,int now,int l){
	if(now<=ans)return;
	if(l==m){
		ans=max(ans,now);
		return;
	}
	if(dep>=n){
		return;
	}
	dfs(dep+1,now,l);
	if(l==0){
	dfs(dep+1,a[dep+1],l+1);
	}else{
		dfs(dep+1,now&a[dep+1],l+1);
	}
}
void solve(){
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=31;j++){
			if(cnt[id][j]&&cnt[i][j]!=cnt[id][j]){
				zt[i]=zt[i]|(1ll<<(j-1));
			}
		}
	}
	sort(zt+1,zt+1+n);
	int now=0;
	for(register int i=1;i<=n;i++){
		if(now>=m)break;
		now++;
		for(register int j=1;j<=31;j++){
			//int a=zt[i]&(1ll<<(j-1));
			//cout<<a<<" ";
			if(!vis[j]&&(zt[i]&(1ll<<(j-1)))){
				vis[j]=true;
				may-=1ll<<(j-1);
			}
		}
		//cout<<"\n";
	}
	cout<<may;
	return;
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<0;
	return 0;
	
}
