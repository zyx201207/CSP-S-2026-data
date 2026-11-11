#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],num=0,ans=0,p=0,tot=0;
char b[200005]; 
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],num+=a[i];
	num/=2,tot=n;
	for(int i=1;i<=n;i++)
	{
		if(p+a[i]<=num)
		{
			p+=a[i];
			int f=0;
			while(true)
			{
				if(f+a[tot]<=a[i])
				{
					f+=a[tot];
					if(b[tot]!=b[i]) ans+=a[tot];
					a[tot]=0,tot--;
				}
				else
				{
					if(b[tot]!=b[i]) ans+=a[i]-f;
					a[tot]-=a[i]-f;
					break;
				}
			}
		}
		else
		{
			int f=0;
			while(true)
			{
				if(f+a[tot]<=a[i]-p)
				{
					f+=a[tot];
					if(b[tot]!=b[i]) ans+=a[tot];
					a[tot]=0,tot--;
				}
				else
				{
					if(b[tot]!=b[i]) ans+=a[i]-f;
					a[tot]-=a[i]-f;
					break;
				}
			}
			break;
		}
	}
	cout<<ans; 
	return 0;
}
