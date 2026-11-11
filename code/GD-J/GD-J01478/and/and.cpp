#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,w,ww,x,a[N],dp[N];

void dfs(ll s,ll o,ll t){
	if(t<x)return;
	if(s==m){
		x=max(x,t);
		return;
	}
	
	if(s==0){
		for(int i=1;i<=n;++i){
			dfs(s+1,i+1,a[i]);
		}
	}else{
		for(int i=o;i<=n;++i){
			dfs(s+1,i+1,t&a[i]);
		}
	}
}
bool cmp(ll xx,ll yy){
	return xx>yy;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(ww==1)ww=a[1];
		else ww=a[i]&ww;
		w=max(a[i],w);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<w;
		return 0;
	}
	if(m==n){
		cout<<ww;
		return 0;
	}
	cout<<x;
	return 0;
}
