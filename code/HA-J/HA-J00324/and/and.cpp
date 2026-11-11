#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
map<ll,bool> poa;
ll ans;
void DFS(ll t,ll su,ll s){
//	cout<<t<<' ';
	if(s==m){
//		cout<<su<<'\n';
		ans=max(ans,su);
		return ;
	}
	for(int i=t+1;i<=n;i++){
		ll b=su&a[i];
		DFS(i,b,s+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<=30;i++){
		ll x=pow(2,i);
		poa[x-1]=true;
	}
	cin>>n>>m;
	bool f=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(poa[a[i]]==false)f=false;
	}
	if(f==true){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else {
		for(ll i=1;i<=n;i++){
			DFS(i,a[i],1);
		}
		cout<<ans;
	}
	
	return 0;
}
//此题没啥好思路，DFS深搜加一个2^n-1的特殊点 
