#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],x;
bool cmp( int x1,int x2 ){
	return x1>x2;
}
int main(){
	freopen( "and.in","r",stdin );
	freopen( "and.out","w",stdout );
	cin>>n>>m;
	for( int i=1; i <= n; i++){
		cin>>a[i];
	}
	if( m == 1 ){
		sort( a+1,a+n+1,cmp );
		cout<<a[1];
	}else if( m == 2 ){
		int ma=0;
		for( int i=1; i <= n; i++){
			for( int j=i+1; j <= n; j++){
				int x=a[i]&a[j];
				if( x > ma )ma=x;
			}
		}
		cout<<ma;
	}else if( m == 3 ){
		int ma=0;
		for( int i=1; i <= n; i++){
			for( int j=i+1; j <= n; j++){
				for( int k=j+1; k <=n; k++){
					int x=a[i]&a[j]&a[k];
					if( x > ma )ma=x;
				}
			}
		}
		cout<<ma;
	}else if( m == 4 ){
		int ma=0;
		for( int i=1; i <= n; i++){
			for( int j=i+1; j <= n; j++){
				for( int k=j+1; k <=n; k++){
					for( int l=k+1; l <=n; l++){
						int x=a[i]&a[j]&a[k]&a[l];
						if( x > ma )ma=x;
					}
				}
			}
		}
		cout<<ma;
	}else if( m == 5 ){
		int ma=0;
		for( int i=1; i <= n; i++){
			for( int j=i+1; j <= n; j++){
				for( int k=j+1; k <=n; k++){
					for( int l=k+1; l <=n; l++){
						for( int o=l+1; o <=n; o++){
							int x=a[i]&a[j]&a[k]&a[l]&a[o];
							if( x > ma )ma=x;
						}
					}
				}
			}
		}
		cout<<ma;
	}else if( m == 5 ){
		int ma=0;
		for( int i=1; i <= n; i++){
			for( int j=i+1; j <= n; j++){
				for( int k=j+1; k <=n; k++){
					for( int l=k+1; l <=n; l++){
						for( int o=l+1; o <=n; o++){
							for( int p=o+1; p <=n; p++){
								int x=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
								if( x > ma )ma=x;
							}
						}
					}
				}
			}
		}
		cout<<ma;
	}else if( m == n ){
		int s=a[1];
		for( int i=2; i <= n; i++){
			s&=a[i];
		}
		cout<<s;
	}
	return 0;
}


