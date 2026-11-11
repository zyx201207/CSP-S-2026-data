#include <bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
char c[200005];
long long num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(c[l]!=c[r]&&a[l]==a[r]) num+=a[l];
		if(c[l]!=c[r]&&a[l]!=a[r])
		{
			num+=max(a[l],a[r]);
			if(min(a[l],a[r])==a[l]) a[r-1]+=(a[r]-a[l]);
			else a[l+1]+=a[l]-a[r];
	    }
	    l++;
	    r--;
	}
	cout<<num;
	return 0;
}
