#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005];
long long N(long long k){
	for(long long i=0;i<(n/2);i++){
		a[i]=a[n/2+1];
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	N(0);
	long long s=0;
	for(long long i=0;i<n;i++){
		long long c=0;
		for(long long j=0;j<n;j++){
			if(a[i]==a[j]){
				c++;
			}
		}
		if(c>=s){
			s=c;
		}
	}
	cout<<s<<endl;
	return 0;
} 
