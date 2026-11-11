#include <bits/stdc++.h>
using namespace std ;
long long n,m ;
long long arr[10005] ;
long long ans=-1 ;
long long y[10005],x[10005] ;
int main() {
	
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	
	cout.tie(0) ;
	cin.tie(0) ;
	
	cin >> n >> m ;
	for (int i=0 ; i<n ; i+=1) {
		y[i]=1 ;
	}
	
	for (int i=0 ; i<n ; i+=1) {
		cin >> arr[i] ;
	}
	
	sort(arr,arr+n) ;
	
	for (long long t=0,i=0 ; i<=n ; i+=1) {
		if ((i==0 or arr[i]==arr[i-1]) and i!=n) {
			if (i==0) {
				x[t]=arr[i] ;
				t+=1 ;
			}
			
			
			if (i!=0) {	
				y[t]+=1 ;
			}
			
			continue ;
		}else{
			x[t]=arr[i] ;
			long long sum=y[t] ;
			long long k=m ;
			
			for (int j=t-1 ; j>=0 ; j-=1) {
				for (int o=0 ; o<y[j] ; o+=1) {
					
					if (k<=0) {
						ans=max(ans,sum) ;
						cout << sum << ' ' ;
						break ;
					}
					
					k-=abs(x[t]-x[j]) ;
					sum+=1 ;
				}
			}
			t+=1 ;
		}
		
		if (i==n) {
			long long sum=y[t] ;
			long long k=m ;
			
			for (int j=t-1 ; j>=0 ; j-=1) {
				for (int o=0 ; o<y[j] ; o+=1) {
			
					if (k<=0) {
						ans=max(ans,sum) ;
						cout << sum << ' ' ;
						break ;
					}
					
					k-=abs(x[t]-x[j]) ;
					sum+=1 ;
				}
			}
		}
	}
	
//	cout << '\n' ;
//	for (int i=0 ; i<n ; i+=1) {
//		cout << y[i] << ' ' ;
//	}
//	cout << '\n' ;
//	for (int i=0 ; i<n ; i+=1) {
//		cout << x[i] << ' ' ;
//	}
	
	cout << ans ;
	
	return 0 ;
	
}
