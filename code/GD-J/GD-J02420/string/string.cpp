#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long y=1,d=0; 
	cin>>n;
	int s[n+5];
	string a[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i]>>a[i];
		d+=s[i];
		if(a[i]==a[i-1]){
			y++;
		}
	}
	if(y==n){
		cout<<0;
	}
	else{
		d/=2;
		cout<<d;
	}
	return 0;
} 
