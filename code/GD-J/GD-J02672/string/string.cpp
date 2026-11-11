#include<bits/stdc++.h>
using namespace std ;
long long n,l ;
string s ;

int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	
	cin>>n ;
	for( int i=1 ; i<=n ; i++ ){
		long long a ;
		char c ;
		cin>>a>>c ;
		for( int j=1 ; j<=a ; j++ )
			s+=c ;
	} 
	int o=s.size()%2 ;
	l=s.size()/2 ;
	string sl,sr ;
	for( int i=0 ; i<l ; i++ )
		sl+=s[i] ;
	for( int i=s.size()-1 ; i>=l+o ; i-- )
		sr+=s[i] ;
	int ans=0 ;
	for( int i=0 ; i<l ; i++ )
		if(sl[i]!=sr[i])
			ans++ ;
	cout<<ans ; 
}
