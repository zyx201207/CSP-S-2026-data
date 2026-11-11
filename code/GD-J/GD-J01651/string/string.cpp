#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,f=0,sum=0;
	string s;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		for(long long j=f;j<f+a;j++){
			s[j]=c;
		}
		f+=a;
	}
	for(long long i=0;i<f/2;i++){
		if(s[i]!=s[f-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
