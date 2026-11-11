#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ll n,m;
	vector<ll> a(n+1);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a.begin(),a.end());
	ll as=m,maX=0;
	for(ll j=1;j<n;j++){
		ll ans=1,x=0,i=j;
		while(as>=0&&i<n){
			if(as-((i-j)+1)*(a[i+1]-a[i])>=0){
				as=as-((i-j)+1)*(a[i+1]-a[i]);
				ans++;
			}else{
				break;
			}
			i++;
			if(i==n) break;
		}
		maX=max(maX,ans);
		as=m;
	}
	cout<<maX<<endl;
	return 0;
}

