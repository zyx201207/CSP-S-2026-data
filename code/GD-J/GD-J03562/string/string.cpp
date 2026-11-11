#include<iostream>
using namespace std;
string a,b;
long long n,jy,num;
char zf;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>jy;
		cin>>zf;
		for(int i=1;i<=jy;i++){
			a+=zf;
		}
	}
	for(long long i=a.length()-1;i>=0;i--){
		b+=a[i];
	}
	for(long long i=0;i<=(b.length()-1)/2;i++){
		if(a[i]!=b[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
