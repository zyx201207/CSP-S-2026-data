#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	long long n,x=0,s=0;
 	cin>>n;
 	long long a[n];
 	char b[n];
 	string c;
 	for(long long i=0;i<n;i++){
 		cin>>a[i]>>b[i];
	 }
 	for(long long i=0;i<n;i++){
 		for(long long j=0;j<a[i];j++){
 			c[x]=b[i];
 			x++;
		}
	}
	for(long long i=0;i<x/2;i++){
		if(c[i]==c[x-i-1]){
			continue;
		}
		else s++;
	}
	cout<<s;
	return 0;
}

