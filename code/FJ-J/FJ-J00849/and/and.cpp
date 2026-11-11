#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll a[200005];
bool b[200005];
ll su=0;
void dg( ll ai,ll x,ll cnt,ll u ){
	if( cnt==m ){
		su=max(su,u);
		return;
	}
	for( int i=ai+1;i<=n;i++ ){
		
		ll v=u&a[i];
		dg( i,a[i],cnt+1,v );
		
	}
	
}
int main(){
	
	freopen( "and.in","r",stdin );
	freopen( "and.out","w",stdout );
	
	cin>>n>>m;
	for( int i=1;i<=n;i++ ){
		cin>>a[i];
	}
	for( int i=1;i<=n;i++ ){
		
		ll u=a[i];
		dg( i,a[i],1,u );
		
	}
	cout<<su;
	
	return 0;
} 
