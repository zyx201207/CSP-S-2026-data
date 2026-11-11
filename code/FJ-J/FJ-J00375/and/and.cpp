#include <bits/stdc++.h>
using namespace std;
long long a[200005],num;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				num=max(num,(a[i]&a[j]));
			}
		}
		cout<<num;
	}
	else if(m==n)
	{
		num=a[1];
		for(int i=1;i<=n-1;i++)
		{
			num=(num&a[i]);
		}
		cout<<num;
	}
	else
	{
		long long t,b[200005],x=1,q=0;
		for(int i=1;i<=n;i++)
		{
			t=1;
			while(t<a[i]+1)
			{
				t*=2;
				if(t==a[i]+1)
				{
					b[x]=a[i];
					x++;
					break;
				}
			}
	    }
	    if(x-1>=m)
	    {
	    	sort(b+1,b+x);
	        cout<<b[x-m];
		}
		else
		{
			sort(a+1,a+n+1);
			if(x>1)
			{
				sort(b+1,b+x);
				q=b[x-1];
				for(int i=1;i<=n;i++)
				{
					if(a[i]==q)
					{
						long long num1=q,num2=q;
						for(int j=i;j<=m+j;j++)	num1=num1&a[j];
						for(int j=i-m;j>=i;j--)	num2=num2&a[j];
						cout<<max(num1,num2);
					}
				}
			}
			else cout<<a[n-1];
		}
	}
	return 0;
}
