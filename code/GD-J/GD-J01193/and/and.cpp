#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,m,nn = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout << a[1];
		return 0; 
	}
	for(long long ii = n;ii >= m;ii--){
		sum = a[ii];
		for(long long i = ii-1;i >= ii-m+1;i--){
			sum = sum & a[i];
			//cout << sum <<"?"<< "\n";
		}
		nn = max(nn,sum);
	}
	cout << nn;
	return 0;
} 
