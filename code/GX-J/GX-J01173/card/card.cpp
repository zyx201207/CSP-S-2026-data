#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+10,M=3e5+10;
ll n,m,a[N],b[M],t[N],z,d[N],t1[N];
bool isok(ll q)
{
	for(int i=1;i<=z;i++)
	{
		if(t[i]==q)return false;
	}
	return true;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(isok(a[j]))
			{
				z++;
			}
			else 
			{
				z=1;
			}
			t[z]=a[j];
		}
		for(ll j=1;j<=z;j++)
		{
			if(d[t[j]]==0)
			{
				t1[t[j]]++;
				d[t[j]]=1;
			}
		}
		for(ll j=1;j<=m;j++)d[i]=0;
	}
	for(ll j=1;j<=m;j++)cout<<t1[j]<<" ";
	return 0;
}
