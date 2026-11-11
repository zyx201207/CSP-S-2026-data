#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[1000001]={0};
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
		{
			s[a[i]+n]++;
		}
		else
		{
			s[abs(a[i])]++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=2*n;i++)
	{
		if(a[i]!=a[i+1])
		{
			if(a[i]>=0&&a[i+1]>=0)
			{
				if(abs(a[i+1]-a[i])*s[n+a[i]]<=m)
				{
					m-=abs(a[i]-a[i+1])*s[n+a[i]];
					s[n+a[i+1]]+=s[n+a[i]];
					a[i]=a[i+1];
//					cout<<m<<endl;
				}
			}
			else if(a[i]<0&&a[i+1]<0)
			{
				if(abs(abs(a[i])-abs(a[i+1]))*s[abs(a[i])]<=m)
					{
					m=m-abs(abs(a[i])-abs(a[i+1]))*s[abs(a[i])];
//					cout<<abs(abs(a[i])-abs(a[i+1]))*s[abs(a[i])]<<" ";
					s[abs(a[i+1])]+=s[abs(a[i])];
					a[i]=a[i+1];
//					cout<<m<<endl;
				}
			}
			else 
			{
				if(abs(a[i+1]-a[i])*s[abs(a[i])]<=m)
				{
					m-=abs(a[i+1]-a[i])*s[abs(a[i])];
//					cout<<abs(abs(a[i])-abs(a[i+1]))*s[abs(a[i])]<<" ";
					s[abs(n+a[i+1])]+=s[abs(a[i])];
					a[i]=a[i+1];
//					cout<<m<<endl;
				}
			}
		}	
	}
	int ans=0;
	for(int i=1;i<=n+n;i++)
	{
		if(s[abs(a[i])]>ans)
		{
//			cout<<s[a[i]]<<">"<<ans<<endl;
			ans=s[abs(a[i])];
		}
	}
	cout<<ans;
	return 0;
} 
