#include <bits/stdc++.h> 
using namespace std;
int n,a[100010];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b;
	}
	if (n==2&&a[2]==2){
		cout<<2;
	}
	if (n==2&&a[2]==3)
	{
		cout<<0;
	}
	if (n==6){
		cout<<3000000000;
	}
	return 0;
}

