#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ( "string.in","r",stdin ) ;
	freopen ( "string.out","w",stdout );
	int n , sum = 0, k ;
	long long l = 0;
	char a[1000008] , m;
	
	cin >> n;
	for(int i = 0 ; i < n;i++){
		cin >> k;
		cin >> m;
		long long d = l;
		for( long long j = l;j < k + d ;j++){
			a[j] = m;
			l++;
		}

	}
	for(long long i = 0; i < l;i++){
		if(a[i] == a[l-i-1]){
			break;
		}else{
			sum++;
		}
	}
	cout << sum;
	return 0;
}