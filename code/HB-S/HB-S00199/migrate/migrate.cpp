#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		if(n==1)
		{
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11 || c==12)
		{
			if(d<2*(a[n]-a[n-1]) || d>=3*(a[n]-a[n-1]))
				cout<<0<<endl;
			else
				cout<<n-3<<endl;
		}
		else
		{
			int res=0;
			for(int i=1;i+3<=n;i++)
			{
				if(d>=(a[i+2]-a[i]) && d>=(a[i+3]-a[i+1]) && d<(a[i+3]-a[i]))
					res++;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}

/*
9 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
*/
