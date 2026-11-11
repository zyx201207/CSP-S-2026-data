#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,minn=99999999;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s;
	}
	if(n<=1)cout<<0;
	else if(n<=2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<minn)minn=a[i];
		}
		cout<<minn;
	}
}  
