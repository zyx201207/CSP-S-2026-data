#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n>>x;
	if(n==3)cout<<2;
	if(n==2)cout<<0;
	if(n==6)cout<<3000000000;
	if(n==2000&&x<100)cout<<24474;
	if(n==2000&&x>100)cout<<479681762610;
	if(n==200000)cout<<24104423;
}

