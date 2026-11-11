#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],cnt0,ans;
void dfs(ll j,ll w,ll le){
	if(j==n+1){
		if(le==m)	ans=max(ans,w);
		return ;
	}
	dfs(j+1,w,le);
	if(le<m){
		if(w==-1)	dfs(j+1,a[j],le+1);
		else	dfs(j+1,w&a[j],le+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ll s=a[1],ma=a[1];
	for(ll i=2;i<=n;i++){
		cin>>a[i];
		s=s&a[i];
		if(a[i]==0)	cnt0++;
		ma=max(ma,a[i]);
	}
	if(n-cnt0<m){
		cout<<0;
		return 0; 
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<s;
		return 0;
	}
	if(n<=2000&&m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n>20){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	dfs(1,-1,0);
	cout<<ans;
	return 0;
}
