#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,m,o=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	int z,n=0;
	char x;
	char l[1599999];
	for(int m=0;m<a;m++){
		cin>>z;
		cin>>x;
		for(int p=n;p<z+n;p++){
			l[p]=x;
		}
		n+=z;
	}
	for(int k=0;k<n/2+1;k++){
		if(l[k]!=l[n-k-1]){
			o+=1;
		}
	}
	cout<<o;
	return 0;
} 
