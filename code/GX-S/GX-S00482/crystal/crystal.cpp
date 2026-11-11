#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.in","w",stdout);
	long long n,m,x,ans=0,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
	{
		x=m;
		s=0;
		for(int j=i;j>=1;j--)
		{
			if(x>0)
			{
				x-=abs(a[i]-a[j]);
				s++;
			}
			else
			break;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
