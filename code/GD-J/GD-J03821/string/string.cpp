#include<iostream>
#include<string>
using namespace std;
string s,h;
int main(){
	freopen("string.in""r",stdin);
	freopen("string.out","w",stdout); 
	long long n,sum=0;
	cin>>n;
    long long v=0;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=v;j<a;j++){
    		s[j]=b;
    	} 
    	v=v+a-1;
	} 
	for(int i=0;i<n;i++){
		h[n-i-1]=s[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!=h[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
