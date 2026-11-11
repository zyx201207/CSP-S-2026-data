#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200100],n,k,cnt[40],cnt2[40];
vector<ll>num[40],num2[40];
ll js(int x)
{
	ll pos,ans=0;
	for(pos=x;pos>=0;pos--)
	{
		if(cnt[pos]>=k)
		{
			ans+=(1<<pos);
			break;
		}
	}
	if(!ans)return 0;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<(int)num[pos].size();i++)
	{
		int tmp=num[pos][i];
		for(int posi=0;tmp;tmp>>=1,posi++)
			cnt[posi]+=(tmp&1),num2[posi].push_back(num[pos][i]-(tmp<<posi));
	}
	for(int i=0;i<=35;i++)
	{
		num[i].clear();
		for(int j=0;j<(int)num2[i].size();j++)num[i].push_back(num2[i][j]);
		num2[i].clear();
	}
	return ans+js(pos-1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i];
		for(int pos=0;tmp;tmp>>=1,pos++)
			cnt[pos]+=(tmp&1),num[pos].push_back(a[i]-(tmp<<pos));
	}
	cout<<js(35);
	return 0;
}