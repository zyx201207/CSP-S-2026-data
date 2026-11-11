#include<bits/stdc++.h>
#define ll long long
#define SNSNMO 110
using namespace std;
const int MAXN=5010;

ll n,m;
ll ans=0,ch,sum;
ll a[MAXN],pre1[MAXN],pre[MAXN][MAXN]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool b=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i==1) continue;
		int x=a[i]-a[i-1];
		pre1[i-1]=x;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)if(i>=1&&i+2<=n&&a[i+2]-a[i+1]!=a[i+1]-a[i]) b=0;
	if(b)
	{
		ch=a[2]-a[1];
		ll cnt=0;
		for(int i=1;;++i)
		{
			cnt+=i*ch;
			if(m<cnt) 
			{
				cout<<i;
				return 0;
			}
		}
	}
	for(ll i=1;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			pre[i][j]=pre[i][j-1]+pre1[j]*(j-i+1);
		}
	}
	for(int len=1;len<=n;++len)
	{
		for(int i=1;i+len-1<n;++i)
		{
			if(m>=pre[i][i+len-1]-pre[i][i-1])
			{
				ans=len+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
