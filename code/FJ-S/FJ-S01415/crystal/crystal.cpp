#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[500010],maxx=INT_MIN,s;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s=1;
		k=m;
		for(int j=i-1;j>=1;j--)
		{
			if(k-(a[i]-a[j])>=0)
			{
				k=k-(a[i]-a[j]);
				s++;
				//cout<<i<<" "<<s<<endl;
				if(s>maxx)
				{
					maxx=s;//cout<<s<<endl;
				}
			}
		}
	}
	cout<<maxx;
	return 0;
} 
