#include <iostream>
using namespace std;
char c[1000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, a;
	cin>>n;
	char b;
	long long m=0 , j=0;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		for(int u=m; u<m+a; u++){
			c[u]=b;
		}
		m=a;
		j+=a;
	}
	long long k=0; 
	for(int i=0; i<j/2; i++){
		if(c[i]!=c[j-i-1]){
			k++;
		}
	}
	cout<<k;
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
