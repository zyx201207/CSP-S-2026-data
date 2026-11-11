#include<bits/stdc++.h>
using namespace std;
int s,maxx,n,m,a[200010],cnt;
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<(1<<n);i++)
	{
		cnt=0;
		s=(1<<n)-1;
		for(int j=0;j<n;j++)
		{
			if((1<<j)&i)
			{			
				s=(s&a[j]);
				cnt++;	
			}
		}
		if(cnt==m)
		{
			if(s>maxx||flag==0)
			{
				maxx=s;
				flag=1;
			}
		}
	}
	cout<<maxx;
	return 0;
}
