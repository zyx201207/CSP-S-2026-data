#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n;
struct dz
{
	LL ll;
	char x;
}a[200010];
LL sum=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ll>>a[i].x;
		sum+=a[i].ll;
	}
	LL f=0;
	int l=1,r=n;
	while(1)
	{
		if(l==r)break;
		if(a[l].x==a[r].x)
		{
			f+=min(a[l].ll,a[r].ll);
			if(f==sum/2)break;
			if(a[l].ll>a[r].ll)
			{
				a[l].ll-=a[r].ll;
				r--;
			}
			else if(a[l].ll<a[r].ll)
			{
				a[r].ll-=a[l].ll;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else if(a[l].x!=a[r].x)
		{
			f+=min(a[l].ll,a[r].ll);
			ans+=min(a[l].ll,a[r].ll);
			if(f==sum/2)break;
			if(a[l].ll>a[r].ll)
			{
				a[l].ll-=a[r].ll;
				r--;
			}
			else if(a[l].ll<a[r].ll)
			{
				a[r].ll-=a[l].ll;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
