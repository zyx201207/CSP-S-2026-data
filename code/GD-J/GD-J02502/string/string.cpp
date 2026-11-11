#include<bits/stdc++.h>
using namespace std;
bool hw(string rx){
	long long len=rx.size();
	for(int i=0;i<len/2;i++){
		if(rx[i]!=rx[len-1-i]) return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string rx="";
	long long a[1000086];
	char b;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>b;
		for(long long f=1;f<=a[i];f++){
			rx=rx+b;
		}
	}
	//cout<<hw(rx);
	long long len=rx.size();
	long long m=0;
	for(long long i=0;i<len/2;i++){
		if(hw(rx)==0){
			break; 
		} 
		if(rx[len-1-i]!=rx[i]){
			rx[len-1-i]=rx[i];
			m++;
		}
	}
	cout<<m;
	return 0;
}
