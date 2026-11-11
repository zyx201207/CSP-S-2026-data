#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
string a;
int x,ans,cnt;
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		ans=ans+x;
		for(int i=0;i<x;i++)
		{
			a=a+y;
		}
	}
	int l=ans/2;
	for(int i=0;i<l;i++)
	{
		if(a[i]!=a[ans-i-1])cnt++;
	}
	cout<<cnt;
}
