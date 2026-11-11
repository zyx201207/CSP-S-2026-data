#include <iostream>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	long long  b[100000],l=0,p=0;
	string h[100000];
	cin>>a;
	for(int i=0;i<a;i++){
	cin>>b[i]>>h[i];
	l+=b[i];
		}
	if(l%2==0){	
	for(int i=0;i<a/2;i++){
		for(int j=a;j>i;j--){
		if(h[i]!=h[j]){
			p+=b[j];
		}	
			}
		}
	}
	if(l%2!=0){
	for(int i=0;i<a/2+1;i++){
		for(int j=a;j>i;j--){
		if(h[i]!=h[j]){
			p+=b[j];
		}	
			}
		}		
	}
	cout<<p;
	return 0;
}

