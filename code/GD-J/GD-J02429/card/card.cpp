#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],vis[500010];
ll ans[300010],pos[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=pos[a[i]];j<=n;j+=pos[a[j]]-j+1){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
