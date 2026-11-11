#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[660007],z=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll ls=m,bq=1,l=1,r=1;
	while(r<n){
		while((a[r+1]-a[r])*bq>ls && l<=r){
			ls+=a[r]-a[l];
			l++,bq--;
		}
		ls-=(a[r+1]-a[r])*bq;
		bq++,r++;
		z=max(z,r-l+1);
	}
	cout<<z<<endl;
	
	return 0;
}

