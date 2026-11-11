#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long y=1e7+9;
ll n,m,sum,num,a[y],b[y];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll maxn=a[1],minn=a[1],maxm,maxi,minn1,mini;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]>maxn)
		{
			maxm=maxn;
			maxn=a[i];
			maxi=i;
		}
		if(a[i]<minn)
		{
			minn1=minn;
			minn=a[i];
			mini=i;
		}
	}
	if(mini==maxi)
	{
		cout<<a[1];
	}
	else
	{
		cout<<max(maxm&maxn,maxn&maxm);
	}
} 
