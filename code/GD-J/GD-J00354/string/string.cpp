#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char b[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n;i<j;)
	{
		if(b[i]==b[j])
		{
			if(a[i]==a[j]) i++,j--;
			else if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
		}
		else
		{
			if(a[i]==a[j]) ans+=a[i],i++,j--;
			else if(a[i]>a[j]) ans+=a[j],a[i]-=a[j],j--;
			else if(a[i]<a[j]) ans+=a[i],a[j]-=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}
