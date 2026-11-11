#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(m==1) 
		{
			if(a[i]>ans)
			{
				ans=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(ans<(a[i]|a[j])) 
			{
				ans=(a[i]|a[j]);
			}
		}
	}
	cout<<ans;
				    return 0;
			    }
