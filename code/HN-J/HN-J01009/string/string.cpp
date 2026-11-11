#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int j=n,l=1;
	while(l<j)
	{
		if(c[l]!=c[j])ans+=min(a[j],a[l]);
		int sl=a[j];
		a[j]=max(a[j]-a[l],0ll);
		a[l]=max(a[l]-sl,0ll);
		if(a[j]==0)j--;
		if(a[l]==0)l++;
	}
	cout<<ans;
	return 0;
}
