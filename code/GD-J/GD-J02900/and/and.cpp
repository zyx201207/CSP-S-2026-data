#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ma)
			{
				ma=a[i];
			}
		}
		cout<<ma;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
