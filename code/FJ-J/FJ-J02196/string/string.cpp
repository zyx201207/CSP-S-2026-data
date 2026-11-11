#include<bits/stdc++.h>
using namespace std;
int n,a[2000010],b=0;
long long x=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		char c;
		cin>>m>>c;
		for(int j=b+1;j<=b+m;j++)
		{
			a[j]=c-'a'+1;
		}
		b+=m;
	}
	for(int i=1;i<=b/2;i++)
	{
		if(a[i]!=a[b-i+1]) x++;
	}
	cout<<x;
	return 0;
}
