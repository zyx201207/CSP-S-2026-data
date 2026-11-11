#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N];
stack<int> v;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int h=0,p;
			for(int k=i;k<=j;k++)
			{
				if(a[k]==a[j])
				{
					h=1;
					p=k;
				} 
			}
			if(h==0) v.push(a[j]);
			else
			{
				for(int k=p;k<=j;k++)
				{
					v.pop();
				}
			}
		}
		for(int j=0;j<v.size();j++)
		{
			c[v.top()]++;
			v.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
