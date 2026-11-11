#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in",'l',stdin);
	freopen("string.out",'r',stdout);
	long long n;
	cin>>n;
	long long n1[n];
	char n2[n];
	for(long long i=0;i<n;++i){
		cin>>n1[i]>>n2[i];
	}
	long long js=0,i=0,j=n-1;
	for(;i<j;){
		if(n1[i]==n1[j]){
			js+=n1[i];
			++i,--j;
		}else if(n1[i]<n1[j]){
			js+=n1[i];
			n1[j]-=n1[i];
			++i;
		}else{
			js+=n1[j];
			n1[i]-=n1[j];
			--j;
		}
	}
	cout<<js;
	fclose("string.in");
	fclose("string.out");
} 
