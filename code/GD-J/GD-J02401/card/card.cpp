#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
vector<int>dui[500005];
map<int,int>tong;
map<int,int>chong;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool yes=1;
	for (int i=1;i<=n;i++)
		{
		scanf("%lld",&a[i]);
		chong[a[i]]++;
		if (i!=1)
			if (a[i]>=a[i-1])yes=0;
		dui[a[i]].push_back(i);
		}
	if (yes)
		{
		int ans=chong[a[1]];
		cout<<ans<<' ';
		for (int i=2;i<=n;i++)
			{
			ans+=chong[a[i]];
			cout<<ans<<' ';
			}
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	for (int i=1;i<=n;i++)
		{
		int j=i;
		while (j<=n)
			{
			int x=upper_bound(dui[a[j]].begin(),dui[a[j]].end(),j)-dui[a[j]].begin();
			if (x==dui[a[j]].size())tong[a[j]]++,j++;
			else j=dui[a[j]][x];
			}
		}
	for (int i=1;i<=m;i++)cout<<tong[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

