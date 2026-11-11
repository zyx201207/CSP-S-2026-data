#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m,maxx=-1;
	cin >> n >> m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==2)
	{
	    for(int i=1;i<=n-1;i++)
	    {
		    for(int j=i+1;j<=n;j++)
		    {
		        if(maxx<(a[i]&a[j]))
		        {
			        maxx=a[i]&a[j];
		        }
		    }
	    }
	}
	else if(m==1)
	{
		sort(a,a+n+1);
		cout << a[n];
		return 0;
	}
	else
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout << maxx;
		return 0; 
	}
	cout << maxx;
	return 0;
}
