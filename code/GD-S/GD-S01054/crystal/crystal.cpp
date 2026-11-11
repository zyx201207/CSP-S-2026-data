#include<bits/stdc++.h>
using namespace std;
int n,m,mx=INT_MIN;
int a[500005];
int suiji(int l,int r)
{
	return rand()%(r-l+1)+l;
}
void qs(int l,int r)
{
	int mid=a[suiji(l,r)];
	int i=l,j=r;
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(mid<a[j]) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j) qs(l,j);
	if(i<r) qs(i,r);
}
bool cw()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) return 0;
	}
	return 1;
}
int check(int x)
{
	int s=m,cnt=1;
	for(int i=x-1;i>=1;i--)
	{
		if(s-(a[x]-a[i])>=0)
		{
			cnt++;
			s-=(a[x]-a[i]);
		}
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(cw())
	{
		if(m>=1)
		{
			int cnt=2,la=3;
			while(la<=n)
			{
				cnt++;
				la*=2;
			}
			cout<<cnt;
		}
		else cout<<1;
	}
	qs(1,n);
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,check(i));
	}
	cout<<mx;
	return 0;
}
