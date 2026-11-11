#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],l,r,b[3005],o,c[3005];
bool f=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	b[a[i]]++;
    	if(b[a[i]]==2)
    	{
    		o=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==o)
		{
			if(f==0)
			{
				l=i;
				f=1;
			}
			else r=i;
		}
	}
	c[a[l]]=l;
	for(int i=1;i<=n;i++)
	{
		if(i<l)
		{
			c[a[i]]=i;
		}
		if(i>l&&i<r)
		{
			c[a[i]]=i-l;
		}
		if(i>r) c[a[i]]=n-l+1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
