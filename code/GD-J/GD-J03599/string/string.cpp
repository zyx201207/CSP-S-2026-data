#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	string b[n],c[n*n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long k=0,suma=0;
	for(long long i=0;i<n;i++){
		int s=a[i];
		while(s){
			c[k]=b[i];
			s--;
			k++;	
		}
	}
	for(long long i=0;i<=(k+1)/2;i++){
		if(c[i]!=c[k-i]){
			suma++;
		}
	}
	cout<<suma;
	return 0;
}
