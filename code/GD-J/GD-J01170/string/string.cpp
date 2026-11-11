#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll n,cj=0,ans=0,sum=0,x[MAXN];
string s;
char c[MAXN],cs[MAXN],c1[MAXN],c2[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>cs[i];
		for(int j=sum+1;j<=x[i]+sum;j++)
		{
			c[j]=cs[i];
		}
		sum+=x[i];
	}
	if(sum%2!=0)
	{
		ll js=1;
		for(int i=1;i<=(sum-1)/2;i++)
		{
			c1[i]=c[i];
		}
		for(int i=(sum+1)/2;i<=sum;i++)
		{
			c2[js]=c[i];
			js++;
		}

		js=(sum-1)/2;
		for(int i=1;i<=(sum-1)/2;i++)
		{
			if(c[i]!=c2[js])
			{
				ans++;
			}
			js--;
		}
	}
	else if(sum%2==0)
	{
		ll js=1;
		for(int i=1;i<=sum/2;i++)
		{
			c1[i]=c[i];
		}
		for(int i=(sum/2)+1;i<=sum;i++)
		{
			c2[js]=c[i];
			js++;
		}
		js=sum/2;
		for(int i=1;i<=sum/2;i++)
		{
			if(c1[i]!=c2[js])
			{
				ans++;
			}
			js--;
		}
	}
	cout<<ans;
	return 0;
}
