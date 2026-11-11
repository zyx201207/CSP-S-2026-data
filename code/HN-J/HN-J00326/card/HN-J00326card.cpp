#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],t[500005];
int main()
{
	int n,m,k,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(b!=n+1)
	{
		b++;
		for(int i=b;i<=n;i++)
		{
			k=a[i];
			if(t[k]==0) t[k]++;
			else
			{
				for(int j=i-1;j>=1;j--)
				{
					if(a[j]==k)
					{
						break;
					}
					t[a[j]]=0;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			s[i]+=t[i];
			t[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
