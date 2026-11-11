#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,mask=0,ans=0,maxx=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n>2000&&maxx>20000)
	{
		int ans=(1<<20);
		sort(a+1,a+n+1,greater<int>());
		for(i=1;i<=m;i++) ans|=a[i];
		cout<<ans;
		return 0;
	}
	for(mask=0;mask<=maxx;mask++)
	{
		int k=0;
		for(i=1;i<=n;i++)
			if((mask&a[i])==mask)
				k++;
		if(k>=m) ans=max(ans,mask);
	}
	cout<<ans;
	return 0;
}
