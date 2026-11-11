#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,q=0,p=0,s=0,w=0;
	cin>>n;
	int a[n+5];
	string b[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		p+=a[i];
	}
	string c[p+5];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[s]=b[i];
			s++; 
			
		}
	}
	for(int i=0;i<p/2;i++){
		if(c[i]!=c[p-1-i]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
