//准考证号：GZ-S00351 姓名：曹一柏
#include<bits/stdc++.h>
using namespace std;
long long n,k,p;
long long a[500005];
int main(){
	freopen("cryatal.in","r",stdin);
	freopen("cryatal.out","w",stdout);
	cin>>n,k;
	for(long long i=0;i<n;i++){
        cin>>a[i];
	}
	sort(a,a+n);
	long long z=a[n/2];
	for(long long i=0;i<n;i++){
		if(a[i]==z){
			p++;
		}
	}
	for(long long i=n/2+1;i>0;i--){
		long long cnt=0;
		for(long long j=0;j<i-1;j++){
			cnt+=(z-a[j]);
		}
		if(cnt<=k){
			cout<<i+p+1;
			break;
		}
		else continue;
	}
	return 0;
}
