//#include<stdc++/bits.h>
#include<iostream>
using namespace std;
int a=4,n,b2[1000000],i=1,j,k,t=0;
string c1,s1,c2,s2;
char s,b[1000000];
bool r;
int main(){
	cin>>n;
	k=1;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(j=k;j<k+a;j++){
			b[j]=s;
		}k+=a;
	}
	if(k%2==0)r=true;
	else r=false;
//	for(i=1;i<=k;i++){
//		cout<<b[i];
//	}
	if(r){
		for(i=1;i<=k/2;i++){
			if(b[i]!=b[k-i])t++;
		}
	}
	else{
		for(i=1;i<k/2;i++){
			if(b[i]!=b[k-i])t++;
		}
	}
	cout<<t;
	
	
	
	return 0;
} 
