#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],c;
char a[200005];
int main(){
	freopen( "string.in","r",stdin );
	freopen( "string.out","w",stdout );
	cin>>n;
	for( long long i=1; i <= n; i++){
		cin>>x[i]>>a[i];
	}
	int L=1,R=n;
	while( L < R ){
		if( x[L] > x[R] ){
			if( a[L] != a[R] ){
				c+=x[R];
			}
			x[L]-=x[R],x[R]=0,R--;
		}else if(  x[L] < x[R] ){
			if( a[L] != a[R] ){
				c+=x[L];
			}
			x[R]-=x[L],x[L]=0,L++;
		}else{
			if( a[L] != a[R] ){
				c+=x[L];
			}
			x[L]=0,x[R]=0,L++,R--;
		}
	}
	cout<<c;
	return 0;
}


