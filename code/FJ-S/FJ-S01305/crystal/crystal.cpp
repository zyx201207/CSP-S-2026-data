#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct st
{
	int s;
	int cha;
} a[N];
bool cmp(st a,st b)
{
	return a.s<b.s;
}
int n,m,k,ans,len,cnt[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	k=m;
	cnt[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		a[i].cha=a[i].s-a[i-1].s;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			m-=a[j].cha*(j-cnt[len]);
			if(m<0)
			{
				len++;
				cnt[len]=j-cnt[len-1];
				ans=max(ans,cnt[len]);
				m=k;
			}
		}
	}
	cout<<ans;
	
	





	return 0;
}

