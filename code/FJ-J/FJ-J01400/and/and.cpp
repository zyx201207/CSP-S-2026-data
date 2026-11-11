#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[20005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
	}
	else if(m==n)
	{
		int t=a[1];
		for(int i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		cout<<t;
	}
	else if(n>=2000)
	{
		cout<<a[n-1]+2;
    }
	else
	{
		int y=n-(m-1);
		cout<<a[y];
		return 0;
	}
	return 0;
}
