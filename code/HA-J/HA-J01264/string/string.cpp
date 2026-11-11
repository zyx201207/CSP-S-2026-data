#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
freopen("travel.in","w",stdin);
freopen("travel.out","c",stdout);
	long long n,x;
	cin>>n;
	char y;
	long long he=0;
	string a;long long len=0;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=len;j<len+x;j++){
			a[j]=y;
		}
		len+=x;
	}
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-1-i]){
			he++;
		}
	}
	cout<<he;
	return 0;
} 
