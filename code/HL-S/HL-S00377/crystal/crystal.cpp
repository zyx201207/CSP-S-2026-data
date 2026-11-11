#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ma=0;
vector<ll>ans(500010,1);
vector<ll>a(500010),t(500010);
void he(int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r)
	{
		if(a[i]<a[j])
		{
			t[k++]=a[i++];
		}
		else
		{
			t[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		t[k++]=a[i++];
	}
	while(j<=r)
	{
		t[k++]=a[j++];
	}
	for(int x=l;x<=r;x++)
	{
		a[x]=t[x];
	}
}
void fen(int l,int r)
{
	int m=(l+r)/2;
	if(l>=r)
	{
		return;
	}
	fen(l,m);
	fen(m+1,r);
	he(l,m,r);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	fen(0,n-1);
	for(int i=0;i<n;i++)
	{
		int t=m;
		for(int j=i;j>0;j--)
		{
			int x=a[i]-a[j];
			if(t>=x)
			{
				t-=x;
				ans[i]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ma<ans[i])
		{
			ma=ans[i];
		}
	}
	cout<<ma;
	return 0;
}
