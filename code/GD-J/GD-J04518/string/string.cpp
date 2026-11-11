#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	string a;
	long long con;
	char zi;
	long long d=0;
	for(long long i=0;i<n;i++){
		cin>>con>>zi;
		d+=con;
		for(long long j=0;j<con;j++){
			a+=zi;
		}
	}
	long long c=d-1;
	long long cot=0;
	for(long long i=0;i<d/2;i++){
		if(a[i]！=a[c]){
			cot++;
		}
		c--;
	}
	cout<<cot;
	return 0;
}
