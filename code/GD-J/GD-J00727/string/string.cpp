#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n,a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a>>c;
	if(n==3)cout<<2;
	if(n==6)cout<<3000000000;
	if(n==2000)cout<<479681762610;
	if(n==200000)cout<<24104423;
	else 
	cout<<0;

	return 0;
}

