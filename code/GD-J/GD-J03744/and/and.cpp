#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n,m;
ll a[200020];
ll ans,mx;
bool vis[200020];

void dfs(ll sum,int num){
	if(num>=m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			dfs(sum & a[i],num+1);
			vis[i]=false;
		}
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	
	
	if(m==1){
		cout<<mx<<'\n';
	}
	else if(m==n){
		ll t=a[1];
		for(int i=2;i<=n;i++){
			t &= a[i];
		}
		cout<<t<<'\n';
	}
	
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i==j) continue;
				ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans<<'\n';
	}
	
	else if(m==n-1){
		ll t=a[1];
		for(int i=2;i<=n;i++){
			t &= a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,t | a[i]);
		}
		cout<<ans<<'\n';
	}
	
		
	else{
		for(int i=1;i<=n;i++){
			vis[i]=true;
			dfs(a[i],1);
			vis[i]=false;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
