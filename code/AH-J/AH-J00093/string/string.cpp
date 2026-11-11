#include<bits/stdc++.h>
using namespace std;

int a[10000+10];
char c[10000+10];

int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		cin>>a[i]>>c[i];
	}
	
	if(n==1){
		cout<<0;
	}
	for(int i=0;i<n;i++){
			if(c[i]==c[i+1]){
				cout<<0;
				break;
			}
	}
	

	return 0;
}
