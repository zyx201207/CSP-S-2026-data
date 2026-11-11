#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int N=5e5+10 ;
int a[N],pre[N] ;
signed main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int n,m ;
	cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
	}
	sort(a+1,a+1+n) ;
	int water=0 ;
	for(int i=1;i<=n;i++){
		int sum=0 ;
		for(int j=1;j<i;j++){
			sum+=a[i]-a[j] ;
			if(sum==m){
				water=i ;
				for(int k=i+1;k<=n;k++){
					if(a[k]==a[i]){
						water++ ;
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(a[i]==a[j]){
							cout << n ;
							return 0 ;
						}
					}
				}
			} 
		}
	}
	cout << water ;
	return 0 ;
}
