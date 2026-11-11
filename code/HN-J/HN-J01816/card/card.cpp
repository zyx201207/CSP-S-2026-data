#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=3e5+10;
ll n,m,a[N],f[M],last[M],sta[M];
vector<ll> app[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		app[a[i]].push_back(i);
		if(!sta[a[i]]) sta[a[i]]=i;
		last[a[i]]=i;
	}
	f[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		if(i==a[n]) continue;
		if(i==a[1]&&(ll)app[i].size()==1)
		{
			f[a[1]]=1;
			continue;
		}
		for(ll idx:app[i])
		{
//			cout<<idx<<' ';
			if(i==a[1]&&idx==1)
			{
				f[i]++;
				continue;
			}
//			cout<<1;
			bool flag=false;
//			cout<<idx<<' ';
			ll lst=0;
			for(int j=idx-1;j>=1;j--)
			{
//				cout<<1;
				if(last[a[j]]>idx)
				{
					lst=j;
					flag=true;
					break;
				}
			}
			if(flag)
			{
//				cout<<lst<<' ';
				f[i]+=(idx-lst);
			}
			else
			{
				if(i==a[1]) f[i]+=(idx-1);
				else f[i]+=idx;
			}
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
	cout<<'\n';
	return 0;
}
