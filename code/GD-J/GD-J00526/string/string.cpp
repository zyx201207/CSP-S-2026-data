#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long nm=0;
	vector<long long> a(n,0);
	vector<long long> qz(n,0);
	vector<char> c(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		nm+=a[i];
		qz[i]=nm;
	}
	long long num=0;
	long long i=0,j=n-1;
	nm=(nm+1)/2;
	while(qz[i]<=nm && qz[j]>=nm && i<=n-1 && j>=0){
		if(a[i]>=a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j]){
				num+=a[j];
			}
			j--;
		}else{
			a[j]-=a[i];
			if(c[i]!=c[j]){
				num+=a[i];
			}
			i++;
		}
	}
	if(c[i]!=c[j]){
		num+=min(a[i],a[j]);
	}
	cout<<num;
	return 0;
}
