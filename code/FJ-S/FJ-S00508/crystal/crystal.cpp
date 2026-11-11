#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m1,ma=-999999999;
	cin>>n>>m1;
	long long a[500050]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		long long b=1;
		long long p=1,q=1;
		long long m=m1;
		while(1){
			if(a[i]-a[i-p]>=a[i+q]-a[i] && a[i+q]-a[i]<=m && q-i>=1 && q-i<=n){
				m=m-a[i+q]+a[i];
				b++;
				q++;
				continue;
			}
			else if(a[i+q]-a[i]>=a[i]-a[i-p] && a[i]-a[i-p]<=m && i-p>=1 && i-p<=n){
				m=m-a[i]+a[i-p];
				b++;
				p++;
				continue;
			}
			else break;
		}
		ma=max(b,ma);
	}
	cout<<ma;
}
