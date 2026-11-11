#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","R",stdin);
	freopen("string.out","W",stdout);
	int n,a[200001],t=1,s=0;
	char c[200001],b[200001];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=t;j<=t+a[i];j++)b[i]==c[i];
		t+=a[i];
	}
	for(int i=1;i<=t/2;i++)
	{
		if(b[i]!=b[t-i])s+=1;
	}
	cout<<s;
	return 0;
}
