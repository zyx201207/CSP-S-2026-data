#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)ans[i]=1;
	for(int i=0;i<n;i++)
	{
		int c=0,s=i-1; 
		while(c<=m&&s>=0)
		{
			c+=a[i]-a[s];
			if(c<=m)ans[i]++;
			s--;
		}
	}
	int maxx=0;
	for(int i=0;i<n;i++)if(ans[i]>maxx)maxx=ans[i];
	cout<<maxx;
	return 0;
 } 
