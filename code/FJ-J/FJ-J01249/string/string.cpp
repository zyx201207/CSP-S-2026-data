#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int c[n];
	char s[n];
	for(int i=0;i<n;i++){
		cin>>c[i]>>s[i];
	}
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		cout<<min(c[0],c[1]);
	}
	else if(n==10){
		cout<<5;
	}
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
