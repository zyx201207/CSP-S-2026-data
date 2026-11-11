#include<bits/stdc++.h>
using namespace std;
long long n,an;
struct node{long long x;char y;}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1,j=n,ii=1,jj=a[n].x;i<j;)
	{
		if(a[i].x-ii+1<=jj)
		{
			if(a[i].y!=a[j].y)an+=a[i].x+1-ii;
			jj-=a[i].x+1-ii;
			if(!jj)jj=a[--j].x;
			ii=1,i++;
		}
		else
		{
			if(a[i].y!=a[j].y)an+=jj;
			ii+=jj;
			jj=a[--j].x;
		}
	}
	cout<<an;
	return 0;
}
