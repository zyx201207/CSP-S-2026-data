#include <bits/stdc++.h>
using namespace std;

const long long MAXN=2e5+10;
struct node
{
	long long a;
	char c;
}t[MAXN];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>t[i].a>>t[i].c;
	}
	long long l=1,r=n,ans=0;
	while(l<r)
	{
		if(t[l].c!=t[r].c)
		{
			if(t[l].a<=t[r].a)
			{
				ans+=t[l].a;
				t[r].a-=t[l].a;
				t[l].a=0;
			}
			else
			{
				ans+=t[r].a;
				t[l].a-=t[r].a;
				t[r].a=0;
			}
			if(t[l].a<=0) l++;
			if(t[r].a<=0) r--;
		}
		else
		{
			if(t[l].a<=t[r].a)
			{
				t[r].a-=t[l].a;
				t[l].a=0;
			}
			else
			{
				t[l].a-=t[r].a;
				t[r].a=0;
			}
			if(t[l].a<=0) l++;
			if(t[r].a<=0) r--;
		}
	}
	cout<<ans;
	return 0;
}