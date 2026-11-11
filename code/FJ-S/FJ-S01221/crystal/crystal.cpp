#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005],maxn=INT_MIN,maxa=INT_MIN,mina=INT_MAX;
ll n,m;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{315275;3845;
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(ll i=1ll;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>maxn)maxn=b[a[i]];
	}
	if(m==0)cout<<maxn;
	else
	{
		sort(a+1ll,a+n+1ll,cmp);
		for(ll i=1ll;i<n;i++)
		{
			if(a[i]==a[i-1])break;
			ll k=0,j;
			for(j=i+1ll;j<=n+1ll;j++)
			{
				if(j==n+1ll)break;
				if(k+(a[i]-a[j])<=m)k+=a[i]-a[j];
				else break;
			}
			if(j-i>maxn)
			{
				maxn=j-i;
			}
		}
		cout<<maxn;
	}
	return 0;
}