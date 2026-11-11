#include <bits/stdc++.h>
using namespace;
int a[10005];
int n,c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i+2]) c++;
	}
	cout<<s;
	return 0;
}
