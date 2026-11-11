#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m; cin>>n>>m;
	vector<int> a(n+1),cnt(m+1,0),ans(m+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	cnt[a[n]]=n;
	for(int i=1;i<=m;i++) if(i!=a[n]) cnt[i]=ans[i];
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
