#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],cnt,ans,dc;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cnt=m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	dc=abs(a[1]-a[2]);
	for(long long i=1;i<=n;++i)
	{
		if(cnt<=0)break;
		cnt-=dc*i;
		ans++;
	}
	cout<<ans;
	return 0;
}
