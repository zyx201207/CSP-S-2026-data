#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,l=1,r=1;
	cin>>n>>m;
	vector<long long>sz(n+1,-1e12-1),qzhh(n+1);
	for(int q=1;q<=n;q++)
	{
		cin>>sz[q];
	}
	sort(sz.begin(),sz.end());
	for(int q=1;q<=n;q++)
	{
		qzhh[q]=qzhh[q-1]+sz[q];	
	}
	while(l<=r&&l<=n)
	{
		long long cst;
		for(;r<=n;r++)
		{
			cst=(r-l+1)*sz[r]-(qzhh[r]-qzhh[l-1]);
			if(cst>m)
			{
				r--;
				break;
			}
		}
		ans=max(ans,r-l+1);
		l++;
	}
	cout<<ans;
	return 0;
}
