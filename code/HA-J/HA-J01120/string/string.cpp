#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string A;
	long long n,a,sum=0;
	char ai;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a;
		cin>>ai;
		for(long long k=0;k<a;k++){
			A=A+ai;
		}
	}
	for(long long i=0;i<A.size()/2;i++){
		if(A[i]!=A[A.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
