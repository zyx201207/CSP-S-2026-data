#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxn=0;
ll a[200010];
bool vis[200010];
ll dfs(ll sum,ll pos){
	if(pos==m){
		return sum;
	}for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			maxn=max(maxn,dfs(sum&a[i],pos+1));
			vis[i]=0;
		}
	}return maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxnn=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(ll i=1;i<=n;i++){
			maxnn=max(maxnn,a[i]);
		}
		cout<<maxnn;
	}else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j) continue;
				maxnn=max(maxnn,a[i]&a[j]);
			}
		}
		cout<<maxnn;
	}else if(m==n){
		maxnn=a[1];
		for(ll i=2;i<=n;i++){
			maxnn=maxnn&a[i];
		}
		cout<<maxnn;
	}
	else cout<<dfs(pow(2,30)-1,0);
	return 0;
}

