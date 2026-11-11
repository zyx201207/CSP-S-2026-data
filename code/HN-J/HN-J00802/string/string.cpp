#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[222222];
	char c[222222];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int x1=c[1];
	for(int i=1;i<=n;i++)
	{
		if(x1!=c[i])
		{
			cout<<i;
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
