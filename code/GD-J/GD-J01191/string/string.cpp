#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans;
long long a[N],c[N];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char z;
		cin>>z;
		c[i]=z-'a'+0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]!=0)i--; 
		if(a[i]==0)continue;
		for(int j=n;j>=i;j--)
		{
			if(a[j]<=0)continue;
			if(a[i]<=0)break;
			if(c[i]!=c[j])
			{
				if(a[i]>a[j])
				{
					a[i]-=a[j];
					ans+=a[j];
					a[j]=0;
					continue;
				}else
				{
					a[j]-=a[i];
					ans+=a[i];
					a[i]=0;
					break;
				}
			}
			else
			{
				if(a[i]>a[j])
				{
					a[i]-=a[j];
					a[j]=0;
					continue;
				}else
				{
					a[j]-=a[i];
					a[i]=0;
					break;
				}
			}
		}
	}
	cout<<ans;
	
	
	return 0;
 } 
