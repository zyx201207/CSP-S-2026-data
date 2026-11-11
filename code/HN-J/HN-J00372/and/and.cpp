#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			maxa=max(maxa,a[i]);
		}
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			maxa=maxa&a[i];
		}
	}
	if(m==2)
	{
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				{
					v.push_back(a[i]&a[j]);
				}
			}
		}
		for(int i=0;i<v.size();i++)
		{
			maxa=max(maxa,v[i]);
		}	
	} 
	cout<<maxa;
	return 0;
}
