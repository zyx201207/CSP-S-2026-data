#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a[5000005];
int n,nt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char b;
		cin>>x>>b;
		for(int j=1;j<=x;j++)a[++nt]=b;
	}
	int l=1,ans=0;
	while(l<nt)
	{
		if(a[l]!=a[nt])ans++;
		l++;
		nt--;
	}
	cout<<ans;
	return 0;
} 
