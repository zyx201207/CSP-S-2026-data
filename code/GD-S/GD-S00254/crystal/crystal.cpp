#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long i=1,j=1;
	while(i<=j&&j<=n){
		while(i<=j&&a[j]*(j-i+1)-(sum[j]-sum[i-1])>m){
			i++;
		}
		maxn=max(maxn,j-i+1);
		j++;
	}
	cout<<maxn;
	return 0;
}
