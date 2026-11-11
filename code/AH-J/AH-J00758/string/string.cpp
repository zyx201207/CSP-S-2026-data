#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
int a[N],n;
char c[N];
LL len,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n;
	LL llen=a[l],rlen=a[r];
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(llen<=rlen)
				rlen-=llen,llen=0;
			else
				llen-=rlen,rlen=0;
		}
		else
		{
			if(llen<=rlen)
				ans+=llen,rlen-=llen,llen=0;
			else
				ans+=rlen,llen-=rlen,rlen=0;
		}
		if(!llen)
			l++,llen+=a[l];
		if(!rlen)
			r--,rlen+=a[r];
	}
	cout<<ans<<'\n';
	return 0;
}
