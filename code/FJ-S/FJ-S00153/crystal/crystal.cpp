#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m,m1,a[N],ans=-200,cnt=0,xc[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			xc[j]=a[i]-a[j];
	    }
		sort(xc+1,xc+n+1);
		for(int j=1;j<=n;j++)
		{
			if(m-xc[j]>=0&&xc[j]>=0)
			{
				m-=xc[j];
				cnt++;
			}
			else if(m-xc[j]<0)			
			{
				break;
			}
		}
		ans=max(ans,cnt);
		cnt=0;
		m=m1;
	}
	cout<<ans;
	return 0;
}
