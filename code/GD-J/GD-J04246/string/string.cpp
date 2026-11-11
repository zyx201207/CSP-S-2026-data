#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
	int num;
	char c;
}a[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	int l=1,r=n,ans=0;
	while(l<r)
	{
		if(a[l].num>=a[r].num)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[r].num;
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
			else
			{
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
			if(a[l].num==0) l++;
		}
		else
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}
			else
			{
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}
			if(a[r].num==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
