#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,zd=0;
	string s;
	long long ans=0,ans1=0;
	bool p=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]>100) p=1; 
		if(p==0)
		{
			for(int j=1;j<=a[i];j++) s=s+c[i];
		}
	}
	if(p==0)
	{
		for(int i=0,j=s.size()-1;i<s.size(),j>i;i++,j--)
		{
			if(s[i]!=s[j]) ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>i+1;j--)
		{
			if(c[i]!=c[j])
			{
				if(a[i]>=a[j]) 
				{
					ans1+=a[i];
					if(n>=3)a[i+1]-=a[i]-a[j];
					a[j]=a[i];
					c[j]=c[i];
				}
				else
				{
					ans1+=a[j];
					if(n>=3) a[i+1]-=a[j]-a[i];
					a[i]=a[j];
					c[i]=c[j];
				}
			}
		}
	}
	if(p==0)cout<<min(ans1,ans);
	else cout<<ans1;
	return 0;
} 
