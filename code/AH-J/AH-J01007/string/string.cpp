#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long um[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		um[i]=um[i-1]+a[i];

	}
	long long k=um[n];
	long long summ=0;
	for (long long i=1;i<=k/2;i++){
		char b,r;
		long long h=2;
		if(i<=um[1]){
			b=c[1];
		}
	else{
		while(h++){
			if(um[h]>=i&&um[h-1]<i){
				b=c[h];
				break;
			}
		}
	}
		long long ii=k+1-i;
		long long j=n+1;
		while(j--){
			if(um[j]>=ii&&um[j-1]<ii){
				r=c[j];
				break;
			}
		}
		if(b!=r){
			summ++;
		}
	}
	cout<<summ;
	return 0;
}
