#include<bits/stdc++.h>
using namespace std;
int n,m;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	if(m==1)
	{
		cout<<a[0]<<endl;
		return 0;
	}
	else if(m==n)
	{
		int ans=1;
		for(int i=0;i<n;i++)
		{
			ans=ans and a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(m==2)
	{
		for(int i=n;i>=0;i--)
		{
			if(a[i]==a[i-1])
			{
				cout<<a[i]<<endl;
				return 0;
			}
			else 
			{
				int ans,maxn=-1;
				for(int i=0;i<n;i++)
				{
					for(int j=i+1;j<n;j++)
					{
						ans=a[i] and a[j];
						maxn=max(maxn,ans);
					}
				}
				cout<<maxn<<endl;
			}
		}
	}
	return 0;
}
