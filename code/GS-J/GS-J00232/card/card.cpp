#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c[1000005],ma=0,d=0,su;
	cin>>n>>m;
	int f=n;
	while(f--)
	{
		cin>>c[d];
		d++;
	}
	if(m==1)
	{
		sort(c,c+n);
		cout<<c[n-1];
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				su=c[i]&c[j];
				if(ma<=su)
					ma=su;
			}
		}
		cout<<ma;
	}
	return 0;
}
