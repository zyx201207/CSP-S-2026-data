#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long j=n-1,k=a[n];
	for(long long i=1;i<m;i++){
		k&=a[j];
		j--;
	}
	cout<<k;
	return 0;
} 
