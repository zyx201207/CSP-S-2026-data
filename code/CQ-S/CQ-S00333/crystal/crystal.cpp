#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N];
long long n,m,ans=0,ma=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		int x=m;
		ans=1;
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]>=0)
			{
				if(a[i]-a[j]<=m)
				{
					x-=a[i]-a[j];
					ans++;
				}
				else
				{
					break;
				}
			} 
			else if(a[i]>=0&&a[j]<0)
			{
				if(a[i]+abs(a[j])<=m)
				{
					x-=a[i]+abs(a[j]);
					ans++;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(abs(abs(a[i])-abs(a[j]))<=m)
				{
					x-=abs(abs(a[i])-abs(a[j]));
					ans++;
				}
				else
				{
					break;
				}
			}
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

