#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],ans;
void dfs(ll deep,ll AND,ll id){
	if(deep>m){
		ans=max(ans,AND);
		return ;
	}
	for(ll i=id+1;i<=n;i++){
		if(deep==1){
			dfs(deep+1,a[i],i);
		}else{
			if(AND==0){
				break;
			}
			ll temp=AND&a[i];
			dfs(deep+1,temp,i);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<ans<<'\n';
	return 0;
}
