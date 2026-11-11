#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long n,m[200005],ans=0,sum1=0,mid=0,sum2=0,h[27],g[27],t=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>m[i]>>a[i];
		sum1+=m[i];
	}
	mid=sum1/2;
	if(sum1%2==0)
	{
		for(int i=1;i<=n;++i)
		{
			sum2+=m[i];
			if(sum2>mid && t==0)
			{
				h[a[i]-'a'+1]+=mid-(sum2-m[i]);
				g[a[i]-'a'+1]+=sum2-mid;
				t=1;
			}
			else if(sum2>mid && t==1)
			{
				g[a[i]-'a'+1]+=m[i];
			}
			else
			{
				h[a[i]-'a'+1]+=m[i];
				if(sum2==mid)
				{
					t=1;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			sum2+=m[i];
			if(sum2>mid+1 && t==0)
			{
				h[a[i]-'a'+1]+=mid-(sum2-m[i]);
				g[a[i]-'a'+1]+=sum2-mid;
				t++;
			}
			else if(sum2>mid && t==1)
			{
				g[a[i]-'a'+1]+=m[i];
			}
			else
			{
				h[a[i]-'a'+1]+=m[i];
				if(sum2==mid)
				{
					t=1;
					h[a[i]-'a'+1]++;
				}
			}
		}
	}
	for(int i=1;i<=26;++i)
	{
		if(h[i]>0)
		{
			ans+=abs(h[i]-g[i]);
		}
	}
	cout<<ans;
	return 0;
}
