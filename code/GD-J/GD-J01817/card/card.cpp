#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int stk[maxn],a[maxn],vis[maxn],tot;
long long cnt[maxn];
long long ans;
bool check(){
	for(int i=1;i<=n;i++) if(a[i]<a[i-1]) return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(check()){
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(int i=1;i<=m;i++) cout <<cnt[i]<<' '; 
		return 0;
	}
	for(int i=1;i<=n;i++){
		tot=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=vis[a[j]]+1;k<=tot;k++){
					vis[stk[k]]=0;
				}
				tot=vis[a[j]];
			}
			else{
				stk[++tot]=a[j];
				vis[a[j]]=tot;
			}
		}
		for(int i=1;i<=tot;i++) cnt[stk[i]]++; 
	}
	for(int i=1;i<=m;i++) cout <<cnt[i]<<' '; 
	return 0;
}
