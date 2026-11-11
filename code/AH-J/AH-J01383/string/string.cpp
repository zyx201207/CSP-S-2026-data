#include<bits/stdc++.h>
using namespace std;
long long n,a[100000];
char c[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(c[1]==c[n]){cout<<0;}
	else cout<<a[1];
	return 0;
}
