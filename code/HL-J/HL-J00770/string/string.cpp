#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int z=2e5+9;
struct node
{
	int sum;
	char ch;
}a[z];
int n;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sum>>a[i].ch;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].ch!=a[r].ch) 
		{
			if(a[l].sum<a[r].sum) 
			{
				ans+=a[l].sum;
				a[r].sum-=a[l].sum;
				l++;
			}
			else if(a[l].sum==a[r].sum) 
			{
				ans+=a[r].sum;
				a[l].sum=a[r].sum=0;
				l++,r--;
			}
			else if(a[l].sum>a[r].sum) 
			{
				ans+=a[r].sum;
				a[l].sum-=a[r].sum;
				r--;
			}
		}
		if(a[l].ch==a[r].ch) 
		{
			if(a[l].sum<a[r].sum) 
			{
				a[r].sum-=a[l].sum;
				l++;
			}
			else if(a[l].sum==a[r].sum) 
			{
				a[r].sum-=a[l].sum;
				l++,r--;
			}
			else if(a[l].sum>a[r].sum) 
			{
				a[l].sum-=a[r].sum;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

*/

