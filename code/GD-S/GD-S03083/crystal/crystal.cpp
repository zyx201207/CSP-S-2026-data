#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	int cnt[n];
	for(int i=0;i<n;i++)
	{
		cin>>cnt[i];
	}
	for(int s=n-1;s>=0;s--)
	{
		for(int j=0;j<n;j++)
	    {
			if(cnt[j]>cnt[s])
		    {
			    swap(cnt[j],cnt[s]);
		    }
		}
	}
	int size[n];
	for(int u=0;u<n;u++)
	{
		if(u!=n-1)
		size[u]=cnt[u+1];
		else
		size[u]=cnt[0];
	}
	int res;
	return 0;
}

