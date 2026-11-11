#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll p[500005];
ll a[500005]={};
ll t[500005]={};
ll su[500005]={};
int main(){
	
	freopen( "card.in","r",stdin );
	freopen( "card.out","w",stdout );
	
	cin>>n>>m;
	ll u=1;
	for( int i=1;i<=n;i++ ){
		cin>>p[i];
	}
	ll b=0;
	
	for( int i=1;i<=n;i++ ){
		memset( a,0,sizeof(a) );
		memset( t,0,sizeof(t) );
		for( int j=i;j<=n;j++ ){
			t[p[j]]++;
			if( t[ p[j] ]>1 ){
				
				bool f=false;
				ll c=b;
				for( int k=0;k<=c;k++ ){
					
					if( a[k]==p[j] ){
						f=true;
						b=k;
					}
					if(f){
						t[ a[k] ]--;
						a[k]=0;
					}
					
				}
				
			}
			a[b]=p[j];
			b++;
		}
		
		for( int j=0;j<=b;j++ ){
			
			if( t[ a[j] ] ){
				su[ a[j] ]++;
			}
			
		}
		
	}
	for( int i=1;i<=m;i++ ){
		
		cout<<su[i]<<" ";
		
	}
	
	return 0;
}
