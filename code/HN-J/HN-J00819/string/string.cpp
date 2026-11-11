#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2&&b[1]==b[2]){
		cout<<0; 
	}else if(n==2&&b[1]!=b[2]){
		if(a[1]%2==0){
			cout<<a[1]/2;
		}else{
			cout<<a[2]/2;
		}
	}
	return 0;
} 
