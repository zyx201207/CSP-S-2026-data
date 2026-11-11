#include <bits/stdc++.h>
using namespace std;
int a[1000005];
char c[27];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1)cout<<"0";
	for(int i=1;i<=n;i++){
		t+=a[i];
		if(c[i]!=c[n+1-i])s+=a[n+1-i];
	}
	cout<<s;
	return 0;
}
