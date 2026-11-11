#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool v[100000];
int mx=0;int n,m;
void dg(int m,int j)
{
	if(m==0)
	{
		mx=max(mx,j);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			dg(m-1,j&a[i]);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		v[i]=1;
		dg(m-1,a[i]);
		v[i]=0;
	}
	cout<<mx;
    return 0;
}
