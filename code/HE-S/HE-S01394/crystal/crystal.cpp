#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,c,m1,s,mn;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		t=a[i];
		m1=m;
		s=1;
		for(int j=i;j>=1;j--)
		{
			c=t-a[j];
			if(c<m1)
			{
				m1-=c;
				s++;
			}
			else
			{
				break;
			}
		}
		if(mn<s)
		{
			mn=s;
		}
	}
	cout<<mn;
	return 0;
 } 
