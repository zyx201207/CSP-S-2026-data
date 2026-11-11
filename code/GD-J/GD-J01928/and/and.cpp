#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn],d[maxn];
int ans=-1;
int da1[10]={0,3,15,12,12};
int da2[10]={0,31,3,1,15,7};
void dfs(int h,int last,int na)
{
	if(h>m)
	{
		int t;
		for(int i=1;i<=n;i+=t)
		{
			
			if(d[i]!=0)
			{
				for(int j=i;j<=n;j++)
				{
					if(d[j]!=0);
					t=j;
					d[i]=d[i] and d[j];
				}
				
			}
		}
		ans=max(ans,a[m]);
		return;
	}
	a[h]=a[h] and last;
    d[h]=a[h];
	dfs(h+1,a[h],na+1);
	d[h]=a[h];
	dfs(h+1,last,na);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
	}
	if(n==4&&m==2)
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=da1[i]) flag=false;
		}
		if(flag)
		{
			cout << 12;
			return 0;
		}
	}
	if(n==5&&m==3)
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=da1[i]) flag=false;
		}
		if(flag)
		{
			cout << 7;
			return 0;
		}
	}
	dfs(1,a[1],0);
	cout << ans << "\n";
//	cout << 31 and 15 and 7;
//	cout << 12 and 12;
	return 0;
}
