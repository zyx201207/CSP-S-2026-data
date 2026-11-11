#include<bits/stdc++.h>
using namespace std;
char a[200005];
unsigned long long ans,q[200005],n,m,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i]>>a[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(q[l]>q[r])
		{
			q[l]-=q[r];
			if(a[l]!=a[r])
			{
				ans+=q[r];
			}
			r--;
		}
		else if(q[l]<q[r])
		{
			q[r]-=q[l];
			if(a[l]!=a[r])
			{
				ans+=q[l];
			}
			l++;
		}
		else
		{
			if(a[l]!=a[r])
			{
				ans+=q[r];
			}
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
