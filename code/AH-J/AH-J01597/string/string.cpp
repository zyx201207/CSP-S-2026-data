#include<bits/stdc++.h>
using namespace std;
long long n;
long long x;
char c;
long long p,q,ans;
struct node
{
	long long l,r,len;
	char y;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>c;
		a[i].l=a[i-1].len+1;
		a[i].r=a[i-1].len+x;
		a[i].y=c;
		a[i].len=x;
	}
	p=1,q=n;
	while(p<q)
	{
		if(a[p].y==a[q].y)
		{
			if(a[p].len==a[q].len)
			{
				p++,q--;
			}
			else if(a[q].len>a[p].len)
			{
				a[q].len-=a[p].len;
				p++;
			}
			else
			{
				a[p].len-=a[q].len;
				q--;
			}
		}
		else
		{
			if(a[p].len==a[q].len)
			{
				ans+=a[q].len;
				p++,q--;
			}
			else if(a[q].len>a[p].len)
			{
				ans+=a[p].len;
				a[q].len-=a[p].len;
				p++;
			}
			else
			{
				a[p].len-=a[q].len;
				ans+=a[q].len;				
				q--;
			}	
		}
	}
	cout<<ans;
	return 0;
}
