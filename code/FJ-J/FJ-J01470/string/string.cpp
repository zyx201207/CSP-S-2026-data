#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;)
	{
		if(a[i]==a[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			i++,j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else
		{
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}
