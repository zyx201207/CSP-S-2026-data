#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d;char e;
char x[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;int k=0;
	for(int i=1;i<=n;i++){
		cin>>a>>e;
		for(int i=0;i<a;i++){
			x[k+i]=e;
		}
		k+=a;
	}
	for(int i=0;i<=k/2;i++){
		if(x[i]!=x[k-i-1]){
			c++; 
		} 
	}
	cout<<c;
	
	return 0;
} 

