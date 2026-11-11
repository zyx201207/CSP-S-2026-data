#include <bits/stdc++.h>
#define let long long
#define str string
#define rt return
#define pb push_back
using namespace std;
let n,m,o = 1,
	mp[500010],vis[500010],a[500010],ans[500010];
let vt[1010][1010];
void dfs(let id){
	if(id>n){
		let b[1010];
		for(let i = 1;i<=n;i++) b[vis[i]] = i;
		for(let i = 1;i<=n;i++) vt[o][i] = b[i];
		o++;
		rt;
	} 
	for(let i = 1;i<=n;i++){
		if(vis[i] == 0){
			vis[i] = id;
			dfs(id+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(let i  =1;i<=n;i++)cin>>mp[i];
	dfs(1);
	for(let i = 1;i<o;i++){
		for(let j = 1;j<=n;j++) cout<<vt[i][j]<<" ";
		cout<<"\n";
	}
	for(let i = 1;i<o;i++){
		for(let j = 1;j<=n;j++) vis[j] = 0,a[j] = 0;
		for(let j = 1,k = 1;j<=n;j++){
			if(vis[vt[o][i]] == 0) {
				vis[vt[o][i]] = 1;
				a[k] = vt[o][i];
				k++;
			}else {
				for(let l = 1,u = 0;l<=n;l++){
					if(u) vis[a[l]] = 0;
					if(a[l] == vt[o][i]) u = 1,k = l+1;
				}
			}
		}
		for(let j = 1;j<=n;j++) ans[a[j]]++;
		
	}
	
	for(let i = 1;i<=n;i++) cout<<ans[i]<<" ";
	rt 0;
	
}
