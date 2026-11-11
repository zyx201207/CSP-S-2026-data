#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,a[200005],t[35],ans;
bool v[200005];
void ttt(int x)
{
	int i = 1;
	while(x)
	{
		if(x%2) t[i]++;
		i++;
		x/=2;
	}
}
void tjt(int x)
{
	int i = 1;
	while(x)
	{
		if(x%2) t[i]--;
		i++;
		x/=2;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	memset(v,true,sizeof(v));
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		ttt(a[i]);
	}
	for(int i = 31;i>=1;i--)
	{
		if(t[i]>=m)
		{
			for(int j = 1;j<=n;j++)
			{
				if(v[j]&&a[j]/int(pow(2,i-1))%2==0)
				{
					tjt(a[j]);
					v[j]=false;
				}
			}
			ans+=pow(2,i-1);
		}
	}
	cout << ans;
	return 0;
}
