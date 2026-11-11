#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int x,m=0;
	char z;
	string n;
	for(int i=0;i<a;i++){
		cin>>x>>z;
		for(int j=0;j<x;j++){
			n+=z; 
		}
	}
	for(int i=0;i<=n.size()/2;i++){
		if(n[i]!=n[n.size()-i-1]){
			m++;
			//cout<<n[i]<<' '<<n[n.size()-i];	
		}
	}
	cout<<m;
	
	
	
	
	return 0;	
}
