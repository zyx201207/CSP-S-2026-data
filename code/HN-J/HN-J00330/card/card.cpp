#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mn=4e6+6;
ll n,m,fa[mn];
ll l,r,a[mn];
ll sum[mn];
ll ans[mn];
//find(ll u){
//	if(fa[u]==u) return u;
//	return fa[u]=find(fa[u]);
//}
int main ( ) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fa[a[i]]=i;
		sum[i]++;
	}
	r=n,l=1;
	while(sum[r]==1){
		ans[a[r]]=r;
		r--;
	}
	while(n--){
		ll bc=r;
		for(int i=l;i<=bc;i++){
			ans[a[i]]++;
			if(fa[a[i]]!=i){
				for(int j=fa[a[i]];j<i;j++){
					a[++r]=a[j];
					a[j]=0;
				}
				ll q=fa[a[i]];
				fa[a[i]]=i;
				i=q;
			}
		}
		for(int i=l;i<=bc;i++)
			if(a[i]) a[++r]=a[i];
		a[l]=bc+1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
