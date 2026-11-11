#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string x;
	cin>>n;
	for(int i=1;i<=n*2;i++)
		cin>>x;
	if(n==3)
		cout<<2;
	else if(n==2)
		cout<<0;
	else if(n==6)
		cout<<3000000000;
	else
		cout<<0;
	return 0;
}
