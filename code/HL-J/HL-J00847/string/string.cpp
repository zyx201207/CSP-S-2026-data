#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 2e5+10 ;
ll a[maxn] ;
char opt[maxn] ;
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0) ;
	int n ; cin>>n ;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>opt[i] ;
	}
	ll ans=0 ;
	for(int l=1,r=n;l<=r;){
		if(a[l]>=a[r]){
			a[l]-=a[r] ;
			if(opt[l]!=opt[r]){
				ans+=a[r] ;
			}
			r-- ;
		}
		else{
			a[r]-=a[l] ;
			if(opt[l]!=opt[r]){
				ans+=a[l] ;
			}
			l++ ;
		}
	}
	cout<<ans ;
	return 0 ;
}