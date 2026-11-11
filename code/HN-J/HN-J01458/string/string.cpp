#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l,sum,maxl=0,j;
	cin>>l;
	if(l%2==0){
		sum=l/2;
	}
	else sum=l/2+1;
	for(int i=0;i<l;i++){
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=0;i<l;i++){
		if(l%2==0)
		cout<<a[0]*l/2;
		return 0;
	}
	cout<<"0";
	return 0;
} 
