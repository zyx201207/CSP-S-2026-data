#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	if(n<=2000)
	{
		if(m==1)
		{
			int mx;
			for(int i=0;i<n;i++)
			{
				if(mx<a[i])
				{
					mx=a[i];
				}
			}
			cout<<mx;
		}
		else if(m==2)
		{
			int mx;
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					if(mx<(a[i]|a[j]))
					{
						mx=(a[i]|a[j]);
					}
				}
			}
			cout<<mx;
		}
		else if(m==n)
		{
			int s=a[0];
			for(int i=1;i<n;i++)
			{
				s=(s|a[i]);
			}
			cout<<s;
		}
	}

    return 0;
}
