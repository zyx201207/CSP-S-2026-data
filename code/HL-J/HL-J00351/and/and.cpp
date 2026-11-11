#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0,a[200030],n,m;
void dfs(ll d,ll sum,ll f){
	if(d>m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=f+1;i<=n;i++){
		if(sum==-1){
		dfs(d+1,a[i],i);	
		}else{
		dfs(d+1,sum&a[i],i);	
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,0);
	cout<<ans;
}
