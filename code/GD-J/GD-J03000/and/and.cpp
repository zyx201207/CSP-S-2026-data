#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e5+5;

int n,m;
int a[maxn];
ll ans=0;

void dfs(ll k,int i,int t){
	if (t>m){
		ans=max(ans,k); 
		return;
	}
	for (int j=i+1;j<=n-(m-t);j++){
		dfs(k&a[j],j,t+1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	for (int i=1;i<=n-m;i++){
		dfs(a[i],i,2);
	}
	cout<<ans;
	return 0;
}
