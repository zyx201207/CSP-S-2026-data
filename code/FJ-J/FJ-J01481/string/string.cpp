#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,k;	
	cin>>a;
	int b[10000];
	string c;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=0;i<a;i++){
		if(b[i]<b[i+1]){
			k=b[i];
		}
		if(b[i+1]<b[i]){
			k=b[i];
		}
	}
	for(int i=0;i<a;i++){
		if(c[i]==c[i+1]){
			cout<<0;
			i=a;
		}
		else {
			cout<<k/2;
			i=a;
		}
	}
	return 0;
}
