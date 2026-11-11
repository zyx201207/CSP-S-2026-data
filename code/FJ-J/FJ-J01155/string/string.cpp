#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int b[10005];
	string c[10005];
	string n[10005];
	int g=0;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
		//cout<<b[i]<<c[i];
		g+=b[i];
		
	}
	int v=0;
	for(int m=0;m<a;m++){
			for(int k=0;k<b[m];k++){
				n[v]=c[m];
				v+=1;
			}
			
			
		}
	
	long long d=0;
	
	for(int j=0;j<g;j++){
		if(n[j]!=n[g-j-1]){
			n[g-j-1]=n[j];
			d+=1;
		}
	}
	cout<<d;
	return 0;
	
}
