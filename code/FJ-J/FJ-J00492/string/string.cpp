#include <bits/stdc++.h>
using namespace std;
int n,len;
long long a[200005],b[200005],ans,ch[200005],sum;
char c[200005];
/*struct str{
	long long id,v;
}s[200005];*/
void check(long long x,long long l)
{
	char c1;
	for(int i=1;i<=n;i++)
	{
		if(x<=b[i])
		{
			c1=c[i];
			break;
		}
	}
	char c2;
	for(int i=1;i<=n;i++)
	{
		if(len-x+1<=b[i])
		{
			c2=c[i];
			break;
		}
	}
	if(c1!=c2)
	{
		ans+=l;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		len+=a[i];
		b[i] = len;
		
	}
	int mid = (len+1)/2;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=mid)
		{
			sum++;
			ch[sum] = b[i];

		}
		else
		{
			if(b[i-1]+1<=mid)
			{
				continue;
			}
			else
			{
				sum++;
				ch[sum] = len-(b[i-1]+1)+1;

			}
		}
	}
	
	
	
	sort(ch+1,ch+sum+1);
	for(int i=1;i<=sum;i++)
	{
		check(ch[i],ch[i]-ch[i-1]);
	}
	cout << ans;
}
