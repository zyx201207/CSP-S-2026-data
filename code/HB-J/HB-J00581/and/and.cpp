#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+9;
ll n,m,a[N],ans,maxn,MN=LONG_LONG_MAX;

void dfs(ll p,ll cnt,ll ad){
	if(cnt==m){
		ans=max(ans,ad);
		return;
	}
	if(p>n) return ;
	
	dfs(p+1,cnt+1,ad&a[p]);
	dfs(p+1,cnt,ad);
}
bool A=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		 cin>>a[i];
		 maxn=max(a[i],maxn);
		 MN=MN&a[i];
	}
	
	sort(a+1,a+n+1);
	for(ll i=1,j=1;i<=n;){
		if(a[i]==j) i++;
		else if(j>a[i]){
			A=0;
			break;
		}
		else j=j*2+1;
		
	}
	if(A) cout<<a[n-m+1];
	else if(m==1) cout<<maxn;
	else if(m==n) cout<<MN;
	else if(m==2){
		ll mx=0;
		for(ll i=1;i<=n-1;i++){
			for(ll j=i+1;j<=n;j++){
				
				ll x=a[i]&a[j];
				mx=max(mx,x);
			}
		}
		cout<<mx;
	}
	else if(n<=20){
		dfs(1,0,LONG_LONG_MAX);
		cout<<ans;
	}
	else{
		ans=LONG_LONG_MAX;
		for(ll i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
