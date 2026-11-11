#include<bits/stdc++.h>
using namespace std;
#define MAXN 200011
int ans=INT_MIN,n,m;
int s[MAXN];
bool vis[MAXN];
inline int max(int a,int b){
	return a>b?a:b;
}
void dfs(int now,int dep){
	if(now<=ans) return;//最优性 
	if(dep==m) ans=max(ans,now);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if((now&s[i])>=ans) dfs((now&s[i]),dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	if(m==n){
		ans=s[1];
		for(int i=2;i<=n;i++){
			ans&=s[i];
		}
		cout<<ans;
		return 0;
	}if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,s[i]);
		cout<<ans;
		return 0;
	}if(m==2){//2000*2000=四百万 能暴力 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,s[i]&s[j]);
			}
		}cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		vis[i]=1;
		if(s[i]>=ans) dfs(s[i],1);
		vis[i]=0;
	}cout<<ans;
	return 0;
}
