#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long x,y,i,l=0,a[1000000];
	char z;
	cin>>x;
	for(i=0;i<x;i++){
		cin>>y>>z;
		l=l+y;
		a[i]=z;
	}
	cout<<l/2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
