#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool fl[200005];
int n,m,maxn;
void f(int x,int y)
{
	if(x>m)
	{
		maxn=max(maxn,y);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(fl[i]==0)
		{
			if(x==1)
			{
				fl[i]=1;
				f(x+1,a[i]);
				fl[i]=0;
			}
			else
			{
				fl[i]=1;
				f(x+1,y&a[i]);
				fl[i]=0;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(1,0);
	cout<<maxn;
	return 0;
}
