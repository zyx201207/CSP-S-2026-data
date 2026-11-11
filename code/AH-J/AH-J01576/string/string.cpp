#include "bits/stdc++.h"
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long a;
	char c;
	string h;
	long long sum=0;	
	long long cnt=0;
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(long long i=sum;i<a+sum;i++){
			h[i]=c;
		}
		sum+=a;
	}
	for(long long l=0,r=sum-1;l<=r;l++,r--){
		if(h[l]!=h[r]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
