#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,mx=LLONG_MIN,a[200005],b[200005];
bool f,vis[200005];
void dfs(ll k,ll sum){
	if(k>=m){
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>2001){
		sort(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	dfs(0,LLONG_MAX);
	cout<<mx;
	return 0;
}
