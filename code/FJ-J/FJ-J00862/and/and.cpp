#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300000],b[100],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--){
		long long x[100]={};
		x[1]=a[i];
		long long sum=1;
		while(x[sum]>1){
			sum++;
			x[sum]=x[sum-1]/2;
			x[sum-1]%=2;
			b[sum-1]+=x[sum-1];
		}
		b[sum]+=1;
		maxx=max(maxx,sum);
	}
	long long ans=0;
	for(int i=maxx;i>=1;i--){
		ans=ans*2+b[i]/m;
	}
	cout << ans;
	return 0;
}
