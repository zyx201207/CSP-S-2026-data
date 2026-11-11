#include<bits/stdc++.h>
using namespace std;
char a[2005];
int b[2005];
int main(void){
	//freopen("string.in","r",stdin);
	//freopen("string.in","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		if(n==1){
			 cout<<0;
			 return 0;
		}
	}	
	if(n==2){
		if(a[1]==a[2]) cout<<0;
		else {
			if(b[1]<b[2]) cout<<b[1];
			else if(b[1]>b[2]) cout<<b[2];
			else cout<<b[2];
		}
	}
	return 0;
}
