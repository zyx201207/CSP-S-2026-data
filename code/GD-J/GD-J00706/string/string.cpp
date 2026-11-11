#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000];
char c[100000];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]==c[i])
		cout<<0;
	}
	return 0;
}
