#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int n,m,a[N],id,ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		m-=((a[i]-a[i-1])*(i-1));
		if(m<0)
			break;
		ans++;
		if(m>0)
			id=i;
	}
	for(int i=id+1;i<=n;i++)
	{
		if(a[i-1]==a[i])
			ans++;
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}
