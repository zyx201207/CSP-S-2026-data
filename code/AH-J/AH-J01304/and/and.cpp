#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,Maxn=30;
ll n,m;
ll a[N];
ll ans;
bool f[N];
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=Maxn-1;k>=0;k--)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]) continue;
			if((a[i]>>k)&1) s++;
		}
		if(s>=m)
		{
			ans|=(1<<k);
			flag=1;
			for(int i=1;i<=n;i++)
			{
				if(!((a[i]>>k)&1)) f[i]=1;
			}
		}
	}
	if(flag) cout<<ans;
	else cout<<0;
	return 0;
}

