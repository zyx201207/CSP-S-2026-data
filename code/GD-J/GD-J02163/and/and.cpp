#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[20005] ;
	cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin  >> a[i] ;
	}
	for(int j=2;j<=n;j++){
		for(int x=j;x>1;x--){
			if(a[x]>a[x-1]){
				swap(a[x],a[x-1]) ;
			}
		}
	}
	cout << a[m] ;
	return 0;
} 
