#include<bits/stdc++.h>
using namespace std;
int n,answer=1;
long long m,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		long long cmp=0;
		int maxx=1;
		for(int j=i-1;j>=1;j--)
		{
			cmp+=(a[i]-a[j]);
			if(cmp<=m)maxx++;
			else break;
		}
		answer=max(maxx,answer);
	}
	cout<<answer;
	return 0;
}
