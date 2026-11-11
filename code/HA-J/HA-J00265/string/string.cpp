#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	long long ans=0;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		ans+=m;
		char b;
		cin>>b;
		for(int j=1;j<=m;j++)
		{
			a+=b;
		}
	}
	string a1,a2;
	for(int i=0;i<=(ans+1)/2-1;i++)
	{
		a1+=a[i];
		a2+=a[ans-i-1];
	}
	int w=0;
	if(a1==a2)
	{
		cout<<0;
	}
	else
	{
		for(int i=0;i<=(ans+1)/2-1;i++)
		{
			if(a1[i]!=a2[i])
			{
				w++;
			}
		}
		cout<<w;
		
	}
}

