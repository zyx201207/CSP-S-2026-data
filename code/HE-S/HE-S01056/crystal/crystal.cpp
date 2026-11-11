#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long l=0,r=1000000000;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    scanf("%lld %lld",&n,&m);
    vector<long long >a(n+1,0),s(n+1,0);
    for(long long i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	if(n<=5001){
		sort(a.begin(),a.end());
		for(long long i=1;i<=n;i++){
	    	s[i]=a[i]-a[i-1];
		}
		for(long long i=1;i<=n;i++){
			long long j=1,d=m;
			if(i+j-1>n){
				break;
			}
			while(d-j*s[i+j-1]>=0&&i+j-1<=n){
				d-=j*s[i+j-1];
				j++;
			}
			num=max(num,j);
		}
		printf("%lld",num);
	}else{
		for(long long i=1;i<=n;i++){
	    	s[i]=a[i]-a[i-1];
		}
		
		long long k=m/s[5]*2;
		while(l<=r){	
			long long m1=l+(r-l)/2;
			if(m1*(m1+1)==k){
				num=m1+1;
				break;
				
			}else if(m1*(m1+1)<k){
				l=m1+1;
			}else{
				r=m1-1;
			}
		}
	}
	printf("%lld",num);
	return 0;
}

