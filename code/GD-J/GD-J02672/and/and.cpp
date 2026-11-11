#include<bits/stdc++.h>
using namespace std ;
const int N=2*1e5+10 ;
int n,m,maxn,mx ;
int a[N],b[N] ;
bool cmp( int c,int d ){
	return c&mx>d&mx ;
}
int main(){
	freopen("and3.in","r",stdin) ;
	freopen("and3.out","w",stdout) ;
	cin>>n>>m ;
	for( int i=1 ; i<=n ; i++ ){
		cin>>a[i] ;
		b[i]=a[i] ;
	}
	for( int i=1 ; i<=n ; i++ ){
		mx=a[i] ;
		sort(b+1,b+n+1,cmp) ;
		int ans=a[i] ;
		//cout<<ans<<endl ;
		for( int j=1 ; j<=m ; j++ ){
			ans&=b[j] ;
		}
		//cout<<a[i]<<" "<<ans<<endl ;
		maxn=max(ans,maxn) ;
	}
	cout<<maxn ;
}
