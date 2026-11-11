#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0,m=0,x=0;
	int a;
	char b[200005],c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			b[j+x]=c;
		}
		x+=a;
		s+=a;
	}
	for(int i=1;i<=s/2;i++)
	{
		if(b[i]!=b[s-i+1])
		{
			m++;
		}
	}
	cout<<m;
	return 0;
}
