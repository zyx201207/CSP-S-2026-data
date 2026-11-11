#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int now;
int ans=0;
void f(int step)
{
	if(step<0)return;
	int sum=0;
	int x=pow(2,step);
	for(int i=1;i<=now;i++)
	{
		if(a[i]/x%2)sum++;
	}
	ans*=2;
	if(sum>=m)
	{
		for(int i=1,j=1;i<=now;i++)
		{
			if(a[i]/x%2)
			{
				a[j]=a[i];
				j++;
			}
		}
		now=sum;
		ans++;
	}
	f(step-1);
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);      //¼ÇµÃÉ¾×¢ÊÍ
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	now=n;
	f(29);
	cout<<ans;
	return 0;
}
