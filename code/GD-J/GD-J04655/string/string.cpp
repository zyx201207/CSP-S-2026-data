#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ans,p1=1,p2=1;
struct node{
	ll len;
	char c;
}a[N],b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].len>>a[i].c;
		b[n-i+1].c=a[i].c;
		b[n-i+1].len=a[i].len;
	}
	while(p1<=n&&p2<=n)
	{
		if(a[p1].c!=b[p2].c)
		{
			if(a[p1].len>b[p2].len)
			{
				ans+=b[p2].len;
				a[p1].len-=b[p2].len;
				p2++;
				
			}
			else if(a[p1].len==b[p2].len)
			{
				ans+=a[p1].len;
				p1++,p2++;
			}
			else
			{
				ans+=a[p1].len;
				b[p2].len-=a[p1].len;
				p1++;
			}
		}
		else
		{
			if(a[p1].len>b[p2].len)
			{
				a[p1].len-=b[p2].len;
				p2++;
			}
			else if(a[p1].len==b[p2].len)
				p1++,p2++;
			else
			{
				b[p2].len-=a[p1].len;
				p1++;
			}
		}
	}
	cout<<ans/2; 
	return 0;
}
