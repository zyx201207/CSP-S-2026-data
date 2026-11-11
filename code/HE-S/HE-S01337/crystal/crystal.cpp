#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for (long long i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for (long long i=n-1;i>=0;i--){
		long long lj=0,gh=1;
		for (long long j=i-1;j>=0;j--){
			if (lj+(a[i]-a[j])>m){
				break;
			}
			lj=lj+a[i]-a[j];
			gh+=1;
		}sum=max(sum,gh);
	}cout<<sum;
	return 0;
}

