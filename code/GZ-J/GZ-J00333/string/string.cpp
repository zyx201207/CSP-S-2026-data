//GZ-J00333-·ëºÆÎÄÇÕ 
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a="";
	string d="";
	int s;
	cin>>s;
	int l=0;
	for(int i=1;i<=s;i++)
	{
		int p;
		string o;
		cin>>p;
		cin>>o;
		l=l+p;
		for(int i=1;i<=p;i++)
		{
			a=a+o;
		}
	}
	int u=0;
	for(int j=l;j>=0;j--)
	{
		int k=0;
		if(a[k]!=a[j])
		{
			u++;
		}
		k++;
	}
	cout<<u/2;
	return 0;
}
