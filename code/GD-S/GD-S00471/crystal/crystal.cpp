#include<bits/stdc++.h>
using namespace std;
int n,m,aa,ans,maxans=1;
int a[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		aa=0;
		ans=1;
		int j=i-1; 
		while(1)
		{
			int p=a[i]-a[j];
			if(aa+p <= m)
			{
				aa+=p;
				ans++;
				j--;
			}
			else
			{
				break;
			}
			if(j==0) break;
		}
		maxans=max(ans,maxans);
	}
	cout<<maxans;
	return 0;
}
