#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	int gg=-1;
	for(int i=1;i<m;i++)
	{
		while(min(a[i],a[i-1]))
		{
			gg++;
			if(a[i]%2==a[i-1]%2)
			{
				c=c+pow(2,gg);
			}
			a[i]/=2;
			a[i-1]/=2;
		}	
		a[i]=c;
		c=0;
		gg=-1;
	}
	cout<<a[m-1];
	return 0;
}
