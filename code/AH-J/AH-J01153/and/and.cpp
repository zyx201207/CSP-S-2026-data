#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int long long
int a[200010];
bool f[200010];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);//12,7,262142,49152,511
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	sort(a+1,a+n+1,cmp);
	int ans=0,jsb=0;
	for(int k=1;k<=n;k++)
	{
		if(m+k-1>n||jsb>=314) break;
		int ansk=a[k];
		for(int i=k+1;i<=m+k-1;i++)
		{
			ansk&=a[i];
		}
		if(ans>=ansk) jsb++;
		else {jsb=0,ans=ansk;}
	}
	cout<<ans;
	/*f[1]=1;
	for(int i=1;i<=n;i++)
		for(int j=;j>=a[i];j--)
			f[j]=f[j&a[i]];
	int ans=0;
	for(int i=1;i<=m;i++) if(f[i]) ans=i;
	cout<<ans;*/
	//what the fuck??
	return 0;
}
