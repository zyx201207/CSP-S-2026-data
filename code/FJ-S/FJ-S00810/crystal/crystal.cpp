#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans,l=1,cmp=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		if(m>=(a[i+1]-a[i])*(i-l+1))//可以 
		{
			m-=(a[i+1]-a[i])*(i-l+1);
			cmp++;
		}else
		{
			while(m<(a[i+1]-a[i])*(i-l+1))
			{
				if(l>i)
				{
					cout<<ans;
					return 0;
				}
				cmp--;
				m+=a[i]-a[l];
				l++;
			}
			m-=(a[i+1]-a[i])*(i-l+1);
			cmp++;
		}
		ans=max(ans,cmp);
		//cout<<cmp<<" ";
	}
	cout<<ans;
	return 0;
}
/*
1 2 3 4 5
2 2 3 4 5
3 3 3 4 5
4 4 4 4 5
5 5 5 5 5
如果我此题AC我将入侵洛谷总部 
*/ 
