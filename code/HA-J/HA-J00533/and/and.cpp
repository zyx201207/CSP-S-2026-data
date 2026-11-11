#include<bits/stdc++.h>
using namespace std;
int n,m,sum,mmax=-1,a[100005];
void f(int floor,int h)
{
	if(floor==m+1)
	{
		if(mmax<sum)
		{
			mmax=sum;
		}
		sum=0;
		return;
	}
	for(int i=h+1;i<=n;i++)
	{
			if(floor==0)
			{
				sum=a[i];
			}
			else
			{
				sum=sum&a[i];
			}
			f(floor+1,i);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(0,0);
	cout<<mmax;
	return 0;
}
