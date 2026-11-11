#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ans=INT_MIN,inf;
void dfs(ll x,ll w,ll cnt){
	if(w==0){
		ans=max(ans,cnt);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if((cnt&a[i])<ans)continue;
		dfs(i,w-1,cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
	}else if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
	}else{
		for(int i=1;i<=n-m;i++)dfs(i,m-1,a[i]);
	}
	cout<<ans;
	return 0;
}
