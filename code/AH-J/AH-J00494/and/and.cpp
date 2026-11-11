#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],k,sum=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n-k+1;i++){
		long long x=a[i];
		for(long long j=i;j<=i+k-1;j++){
			x=x&a[j];
		}
		sum=max(x,sum);
	}
	cout<<sum;
	return 0;
}
