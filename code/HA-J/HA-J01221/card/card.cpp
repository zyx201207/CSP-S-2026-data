#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005],num[300005],head;
struct q
{
	bool x;
	int y;
}b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		head=0;
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]].x)
			{
				c[++head]=a[j];
				b[a[j]].x=1;
				b[a[j]].y=head;
			}
			else
			{
				for(int k=b[a[j]].y+1;k<=head;k++)
				    b[c[k]].x=0;
				head=b[a[j]].y;
			}
		}
		for(int j=1;j<=head;j++)
		{
			num[c[j]]++;
			b[c[j]].x=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
