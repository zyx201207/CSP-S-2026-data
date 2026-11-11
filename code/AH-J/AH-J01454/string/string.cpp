#include<bits/stdc++.h>
using namespace std;
int u=1,uu;
long long n,a[200005],s;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	uu=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(1)
	{
		if(uu<=u)
		{
			break;
		}
		else
		{
			if(b[u]==b[uu])
			{
				a[u]=a[u]-min(a[u],a[uu]);
				a[uu]=a[uu]-min(a[u],a[uu]);
				if(a[u]==0)
				{
					u++;
				}
				if(a[uu]==0)
				{
					uu--;
				}
			}
			else
			{
				if(a[u]>a[uu])
				{
					s=s+a[uu];
					a[u]=a[u]-a[uu];
					uu--;
				}
				else if(a[u]==a[uu])
				{
					s=s+a[uu];
					u++;
					uu--;
				}
				else
				{
					s=s+a[u];
					a[uu]=a[uu]-a[u];
					u++;
				}
			}
		}
	}
	cout<<s;
}
