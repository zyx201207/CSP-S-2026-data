#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],ans;
ll n,m;
bool v[200005];
void bfs(ll g,ll mx){
	if(g==m){
		ans=max(ans,mx);
		g=0;
		memset(v,0,sizeof(v));
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			bfs(g+1,mx&a[i]);
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		v[i]=1;
		bfs(0,a[i]);
		v[i]=0;
	}
	cout<<ans;
	return 0;
}
