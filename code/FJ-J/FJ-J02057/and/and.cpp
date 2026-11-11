#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int n,k;
bool v[200005];
ll ans=-1;
void dfs(ll x,int st){
	if(st>=k){
		if(ans<=x) {
			ans=x;
		}	
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			ll x2=x&a[i];
			dfs(x2,st+1);
			v[i]=false;
			return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(pow(2,31)-1,0);
	cout<<ans;
	return 0;
}
