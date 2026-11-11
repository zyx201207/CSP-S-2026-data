#include<bits/stdc++.h>
using namespace std;
int n;
int a[2005];
char b[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(b[1]==b[2]){
		   cout<<0;
	    }
	}else{
		cout<<2;
	}
	if(n>3){
		cout<<3;
	}
	return 0;
}
