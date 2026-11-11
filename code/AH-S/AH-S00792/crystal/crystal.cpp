#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		c[i]=a[n]-a[i];
	}
	long long s=0;
	long long cnt=0;
	long long mx=0;
	for(long long i=n,j=n;i>=1 and j>=1;i--){
		while(cnt<=m){
			j--;
			if(j==0){
				break;
			}
			cnt+=c[j]-s;
		}
		mx=max(mx,i-j);
		s+=a[i]-a[i-1];
		cnt-=(a[i]-a[i-1])*(i-j);
	}
	cout<<mx;
	return 0;
}


