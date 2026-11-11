#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],ans,mx;
bool vis[N];
void check(){
	ll sum=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(vis[i]){
			if(cnt==0) sum=a[i],cnt=1;
			else sum&=a[i]; 
		}
	}
	ans=max(ans,sum);
	return ;
}
void dfs(ll x,ll cnt){
	if(x==n+1){
		if(cnt==m) check();
		return ;
	}
	vis[x]=true;
	dfs(x+1,cnt+1);
	vis[x]=false;
	dfs(x+1,cnt);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i],mx=max(a[i],mx);
	}
	if(n<=20) dfs(1,0);
	else{
		if(m==1) ans=mx;
		else if(m==n){
			ll sum=a[1];
			for(ll i=2;i<=n;i++) sum&=a[i];
			ans=sum;
		}else{
			ll sum;
			for(ll i=1;i<=n;i++){
				sum=a[i];
				for(ll j=i+1;j<=n;j++){
					sum&=a[j];
					ans=max(sum,ans);
					sum=a[i];
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

