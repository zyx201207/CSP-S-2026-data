#include<bits/stdc++.h>
using namespace std;
int n,a[200200],l=1,r;
char c[200200];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>c[i];
	while(l<r)
	{
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(l>=r) break;
		int minn=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=minn;
		a[l]-=minn;
		a[r]-=minn;
	}
	cout<<ans;
	return 0;
}