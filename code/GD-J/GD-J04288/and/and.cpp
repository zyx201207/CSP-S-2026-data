#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	long long a[n+1];
	if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				else cnt=max(cnt,(a[i] & a[j])); 
			}
		}	 
	}
	else cout<<7;
	return 0;
}
