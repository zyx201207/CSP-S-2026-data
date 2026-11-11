#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	string num;
	for(long long i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=0;j<a;j++){
			num+=b;
		}
	}
	long long a=num.length();
long long s=0;
for(int i=0;i<a/2;i++){
	if(num[i]!=num[a-i-1]){
		s++;
	}
}
cout<<s;
	return 0;
}
