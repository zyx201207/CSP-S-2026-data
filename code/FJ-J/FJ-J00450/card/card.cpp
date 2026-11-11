#include<bits/stdc++.h>
using namespace std ;
queue<long long> a,b,d ;
long long c[999999],sum[99999] ;
int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	long long n,m ;
	cin >> n >> m ;
	for(long long i=1;i<=n;i++){
		long long x ;
		cin >> x ;
		c[i]=x ;
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			a.push(c[j]) ;
		}
		long long dp[99999]={0},k=0 ;
		while(!a.empty()){
			k++ ;
			long long x=a.front() ;
			a.pop() ;
			if(!dp[x]){
				dp[x]=k ;
				b.push(x) ;
			}
			else{
				long long mnbvcxz=dp[x] ;
				k=mnbvcxz ;
				for(long long l=1;l<mnbvcxz;l++){
					long long y=b.front() ;
					
					b.pop() ;
					d.push(y) ;
				}
				while(!b.empty()){
					long long y=b.front() ;
					b.pop() ;
					dp[y]=0 ;
				}
				for(long long l=1;l<mnbvcxz;l++){
					long long y=d.front() ;
					d.pop() ;
					b.push(y) ;
				}
				dp[x]=k ;
				b.push(x) ;
			}
		}
		while(!b.empty()){
			long long x=b.front() ;
			b.pop() ;
			sum[x]++ ;
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << " " ;
	}
	return 0 ;
}

