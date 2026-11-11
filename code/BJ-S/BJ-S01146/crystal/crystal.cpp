#include <iostream>
#include <cmath>
using namespace std;
long long n,m;
long long sum=0,oldsum=9999999999999;
long long num,numi;
long long minnum1=999999999999,minnum2=999999999999;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum+=abs(a[i]-a[i+j]);
		}
		if(sum<oldsum){
			num=a[i];
			numi=i;
			oldsum=sum;
		}
		sum=0;
	}
	for(int i=numi;i<n;i++){
		if(abs(a[i]-num)<minnum1){
			minnum1=a[i];
		}
	}
	for(int i=numi;i>=1;i--){
		if(abs(a[i]-num)<minnum2){
			minnum2=a[i];
		}
	}
	long long minnum=min(minnum1,minnum2);
	


	return 0;
}