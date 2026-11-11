#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[200005];
ll ans;

bool cmp(int x,int y){
	return x>y;
}
/*void dfs(ll pos,ll cnt,ll an){
	if(cnt==m){
		ans=max(ans,an);
		return;
	}
	for(ll i=pos+1;i<n;i++){
		dfs(i,cnt+1,an&a[i]);
	}
}*/

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	/*for(ll i=0;i<n;i++){
		dfs(i,1,a[i]);
	}*/
	sort(a+0,a+n,cmp);
	cout<<a[m-1];
	//cout<<ans;
	return 0;
} 
