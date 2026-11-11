#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int>a(n+5),b(n+5),x(n+5),y(n+5),m(n+5);
	vector<char>s1(n+5),s2(n+5);
	for(int i=1;i<=n;i++)
		cin>>m[i]>>s1[i];
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i-1]+1;
		b[i]=a[i]+m[i]-1;
	}
	int k=a[1]+b[n];
	for(int i=1;i<=n;i++)
	{
		x[i]=k-b[n-i+1];
		y[i]=k-a[n-i+1];
		s2[i]=s1[n-i+1];
	}
	int t=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		char s=s2[i];
		for(int j=t;a[j]<=y[i]&&b[j]>=x[i];j++)
		{
			if(a[j]>=x[i]&&b[j]<=y[i]&&s!=s1[j])//ab属于xy
			{
				ans+=b[j]-a[j]+1;
				
			}
			else if(a[j]<=x[i]&&b[j]>=y[i]&&s!=s1[j])//xy属于ab
				ans+=y[i]-x[i]+1;
			else if(a[j]<x[i]&&b[j]>=x[i]&&s!=s1[j])//ab<xy
				ans+=b[j]-x[i]+1;
			else if(b[j]>y[i]&&a[j]<=y[i]&&s!=s1[j])//ab>xy
				ans+=y[i]-a[j]+1;
			if(b[j]>y[i]) {t=j;break;}
			else if(b[j]==y[i]) {t=j+1;break;}
			
		}
	}
	
	cout<<ans/2;
	return 0;
}
