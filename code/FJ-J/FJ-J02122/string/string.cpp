#include <iostream>
using namespace std;
int i;
int main(){
	int n,d,e;
	cin>>n;
	int a[n];
	char c[n];
	for(i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		d+=a[i];
	}
	char b[d];
	int f;
	for(e=0;e<n;e++){	
		for(i=0;i<a[e];i++){
			b[f]=c[e];
			f++;
		}
	}
	f=0;
	char z[d];
	for(i=d-1;i>=0;i--){
		z[f]=b[i];
	f++;
	}
	f=0;
	for(i=0;i<d/2;i++){
		if(z[i]==b[i]){			
		}
		else{
			z[i]=b[i];
			f++;
		}
	}
	cout<<f;
return 0;
}

