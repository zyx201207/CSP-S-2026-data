#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500001]={0},vis[300001]={0},ans[300001]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i],vis[a[i]]++;
	for(ll i=1;i<=n;i++){
		bool z=1;
		for(ll k=n;k>=i&&z;k--){
			ans[a[k]]++;
			if(vis[a[k]]%2==0&&vis[a[k]]>=2)z=0;
		}
		vis[a[i]]--;
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
}
