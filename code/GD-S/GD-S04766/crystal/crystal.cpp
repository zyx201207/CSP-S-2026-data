#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    sort(a+1,a+n+1,cmp);
    int y=round(n*1.0/2);
    int x=a[y];
    for(int i=1;i<=n;i++)
    {
    	b[i]=abs(x-a[i]);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m>=b[i])
		{
			m-=b[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
 } 
