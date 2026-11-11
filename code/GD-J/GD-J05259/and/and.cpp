#include<bits/stdc++.h>
using namespace std;
long long a[4000005],n,m,res,sum;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		a[n+i] = a[i];
	}
	for(long long i = 1;i <= n + n - m + 1;i++){
		res = a[i];
		for(long long j = 0;j < m;j++){
			res = (res & a[i+j]);
		}
		sum = max(res,sum);
	}
	cout<<sum;
	return 0;
}
