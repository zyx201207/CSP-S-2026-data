#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=0,a[200005],f[200005];
void dfs(ll cur,ll x,ll pi){
	if(cur>m){
		maxn=max(maxn,x);
		return ;
	}
	for(ll i=pi+1;i<=n;i++){
		f[i]=1;
		if(x==0) dfs(cur+1,a[i],i);
		else dfs(cur+1,a[i]&x,i);
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxn;
	return 0;
}
