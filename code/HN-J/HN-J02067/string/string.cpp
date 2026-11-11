#include<bits/stdc++.h>
using namespace std;
const long long M=200007;
struct a{
	long long g;
	char z;
}b[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>b[i].g>>b[i].z;
	}
	bool s=false,c=false;
	for(long long i=0;i<n;i++){
		if(b[i+1].z==b[i].z){
			s=true;
		}
	}
	long long e=0;
	if(s){
		cout<<0;
	}
	return 0; 
} 
