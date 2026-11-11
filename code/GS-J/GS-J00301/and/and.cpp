#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
const int N=2e5+3;
ll n,m,mx,a[N],d[N],vis[N];
void dfs(ll p){
	if(p==m+1){
		ll sum=a[d[1]];
		fo(i,2,m){
			sum=sum&a[d[i]];
		}
		mx=max(mx,sum);
		return;
	}
	fo(i,d[p-1]+1,n-m+p){
		d[p]=i;
		dfs(p+1);
	}
	return;
}


int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	fo(i,1,n){
		cin>>a[i];
	}
	dfs(1);
	cout<<mx;
}

