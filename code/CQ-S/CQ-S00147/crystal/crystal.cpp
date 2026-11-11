#include<bits/stdc++.h>
using namespace std;
namespace did
{
	#define int long long
	int n,m,a[500005],s[500005],ans;
	bool chk(int l,int r)
	{
		int kk=(r-l+1)*a[r]-s[r]+s[l-1];
		return kk<=m;
	}
	signed main()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int l=1,r=1;l<=n;l++)
		{
			while(chk(l,r+1)&&r<n)r++;
			ans=max(ans,r-l+1);
		}
		cout<<ans;
		return 0;
	}
}
signed main()
{
	did::main();
	return 0; 
}

/*
Ê±¼äO(n),¹À·Ö100
*/
