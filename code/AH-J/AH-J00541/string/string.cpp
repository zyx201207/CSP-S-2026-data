#include<bits/stdc++.h>
using namespace std;
int s,x,k,y,n;
char f; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a; 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>f;
		for(int j=0;j<x;j++){
			a[k]=f;
			k++;
		}
	}
	int l=a.size();
	string b;
	for(int i=0;i<l/2;i++){
		b[i]=a[i];
	}
	
	k=0;
	if(l%2==0) x=l/2;
	else x=l/2+1;
	for(int i=l-1;i>x-1;i--){
		if(a[i]!=b[k]) s++;
		k++;
	}
	cout<<s;
}
