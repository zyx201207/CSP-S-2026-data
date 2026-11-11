#include <iostream>
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,t,n=0,o=0;
	std::cin>>a;
	char m,c[100000],d[100000];
	for(int i=0;i<a;i++){
		std::cin>>t>>m;
		for(int i=n;i<n+t;i++){c[i]=m;}
		n=n+t;
	}for(int i=0;i<n;i++){
		d[i]=c[n-i-1];
	}for(int i=0;i<n;i++){
		if(d[i]!=c[i]){o++;}
	}o=o/2;
	std::cout<<o;
	return 0;
}

