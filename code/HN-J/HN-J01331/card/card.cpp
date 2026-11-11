#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],f[200005],ff,s,h[200005],t;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		for(int j=i-1;j>=1;j--)
//		{
//			if(a[i]==a[j])
//			{
//				h[i]=j;
//				break;
//			}
//		}
		if(a[i]<a[i-1]) ff=1;
	}
	if(!ff)
	{
		for(int i=1;i<=t;i++)
		{
			int k=upper_bound(a+1,a+n+1,i)-a-1;
			cout<<k<<" ";
		}
	}
	for(int m=1;m<=t;m++)
	{
//int m=2;
		s=0;
		for(int i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			for(int j=i;j<=n;j++)
			{
				int p=200005;
				for(int k=i;k<j;k++)
				{
					if(a[k]==a[j]&&!f[k])
					{
						f[k]=1;
						p=k;
						break;
					}
				}
//					cout<<p<<" "<<j<<"\n";
				for(int k=p;k<j;k++)
				{
					f[k]=1;
				} 
			}
			for(int j=i;j<=n;j++)
			{
				if(f[j]==0&&a[j]==m)
				{
					s++;
				}
			}
		}
		cout<<s<<" ";
	}
	return 0;
}


