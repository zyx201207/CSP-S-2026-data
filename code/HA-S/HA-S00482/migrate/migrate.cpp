#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000006],l,r,mid,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			l=i;
			r=n;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a[mid]-a[i]>=2*d-1)
				{
					r=mid-1;
				}
				else 
				{
					l=mid+1;
				}
			}
			if(a[mid]-a[i]==2*d-1&&mid-i!=1)
			{
				ans=ans+1;
			}
		}
		cout<<ans<<endl;
	}
}
