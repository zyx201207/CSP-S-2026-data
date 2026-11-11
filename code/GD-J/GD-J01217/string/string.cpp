#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10;
ll n,m,h,t,ans,a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	h=1,t=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(h<t)
	{
		ll minn=min(a[h],a[t]);
		if(c[h]!=c[t]) ans+=minn;
		a[h]-=minn;
		a[t]-=minn;
		if(a[h]==0) h++;
		if(a[t]==0) t--;
	}
	cout<<ans<<endl;
	return 0;
}

