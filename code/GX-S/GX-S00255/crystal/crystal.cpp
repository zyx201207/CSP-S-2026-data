#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
bool vis[500005];
ll ans=LLONG_MIN;
void dfs(ll x){
	if(x>n){
		ll mx=LLONG_MIN,cnt=0,sum=0;
		for(ll i=1;i<=n;i++){
			if(vis[i]==1){
				mx=max(mx,a[i]);
			}
		}
		for(ll i=1;i<=n;i++){
			if(vis[i]==1){
				cnt+=mx-a[i];
				sum++;
			}
		}
		if(cnt>m)return;
		ans=max(ans,sum);
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int c,AB=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)c=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]==c)AB++;
	}
	if(n<=16){
		dfs(1);
		cout<<ans;
	}else if(AB==n-2){
		int i;
		for(i=1;;i++){
			m-=i*c;
			if(m<0){
				i--;
				break;
			}
		}
		cout<<i;
	}
	return 0;
}
