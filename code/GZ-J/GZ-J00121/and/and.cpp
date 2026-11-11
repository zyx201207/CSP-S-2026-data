//贵州师范大学贵安新区附属初级中学 刘炫希 GZ-J00121 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m;
ll ans=-10086;
vector <bool> vis(n+1);
vector <ll>tmp;
vector <ll>a;
void dfs(ll k){
	if (k==m){
		ll ttt=tmp[0];
		for (int i=0;i<m;i++){
			ttt=ttt&tmp[i];
		}
		ans=max(ans,ttt);
		return;
	}
	for (int i=0;i<n;i++){
		if (!vis[i]){
			vis[i]=1;
			tmp.push_back(a[i]);
			dfs(k+1);
			vis[i]=0;
			tmp.pop_back();
		}
	}

} 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		ll tmpp;
		cin>>tmpp;
		a.push_back(tmpp);
	}
	dfs(0);
	cout <<ans;
	return 0;
}

