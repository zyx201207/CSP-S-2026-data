#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],sum=0,m,nn = -1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(long long ii = 1;ii <= n;ii++){
		cout << a[ii];
	}
	return 0;
} 
