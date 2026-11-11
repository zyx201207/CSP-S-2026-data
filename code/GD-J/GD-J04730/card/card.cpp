#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],cnt[300001],ans[300001];
vector<int> p[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[a[i]].push_back(i);
	}
	for(int i=n;i>=1;i--)
	{
		int p1=lower_bound(p[a[i]].begin(),p[a[i]].end(),i)-p[a[i]].begin()+1;
		if(p1>=(*(p[a[i]].end())))
			p1=0;
		int p2=p[a[i]][p1];
		cnt[a[i]]++;
		for(int j=i;j<=p2-1;j++)
			cnt[a[j]]--;
		for(int j=1;j<=m;j++)
			if(cnt[j])	
				ans[j]++;					
	} 
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
} 
