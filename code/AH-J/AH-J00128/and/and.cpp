#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200000+10],maxn;
void dfs(ll cur,ll pre,ll sum){
	if(cur==m){
		maxn=max(maxn,sum);
		return ;
	}
	for(ll i=pre+1;i<=n;i++){
		dfs(cur+1,i,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dfs(1,i,a[i]);
	}
	cout<<maxn;
	return 0;
}
