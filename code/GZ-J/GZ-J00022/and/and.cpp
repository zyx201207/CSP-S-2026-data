//GZ-J00022,商梓辰，贵阳市第三中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;cin>>n>>m;
	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end(),cmp);
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;	
	return 0;
	 
} 

