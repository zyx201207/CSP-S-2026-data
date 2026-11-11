#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
string a;
ll len=0;
int main(){
	
	//freopen( "string.in","r",stdin );
	//freopen( "string.out","w",stdout );
	
	cin>>n;
	for( int i=0;i<n;i++ ){
		
		ll ai;
		char c;
		cin>>ai>>c;
		len+=ai;
		for( int j=1;j<=ai;j++ ){
			a+=c;
		}
		
	}
	ll lt,rt;
	if( len%2==1 ){
		lt=len/2;
		rt=lt;
	}else{
		rt=len/2-1;
		lt=rt+1;
	}
	ll su=0;
	
	while( rt>=0 && lt<len ){
		
		if( a[rt]!=a[lt] ){
			su++;
		}
		rt--;
		lt++;
	}
	cout<<su;
	
	return 0;
} 
