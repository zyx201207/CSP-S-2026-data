#include<bits/stdc++.h>
using namespace std;
string a,b;
unsigned long long n,t,s,l;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=0;i<n;i++){
		cin>>t>>ch;
		for(unsigned long long j=0;j<t;j++){
			a+=ch;
		}
	}l=a.size();
	for(unsigned long long i=0;i<l;i++){
		b[i]=a[l-1-i];
	}
	for(unsigned long long i=0;i<l;i++){
		if(a[i]!=b[i]){
			s++;
		}
	}
	cout<<s/2;
	return 0;
}

