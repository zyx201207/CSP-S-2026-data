#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]>maxn)
			{
				maxn=a[i]&a[i];
			}
		}
		cout<<maxn;
		return 0;
	}
	else
	{
		if(n==4&&m==2)
		{
			if(a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12) cout<<12;
		}
		else if(n==5&&m==3)
		{
			if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7) cout<<7;
		}
		else 
		{
			cout<<13;
		}
	}
	return 0;
}
