#include<iostream>
#include<cstdio>
int a[500005],b[300005],c[300005];
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;)
		{
//			cout<<j<<' ';
			c[a[j]]++;
//			cout<<c[a[j]]<<' ';
			j=b[a[j]]+1;
		}
//			for(int k=0;k<m;k++)cout<<c[k]<<' ';
//			cout<<'\n';
	}
	for(int i=0;i<m;i++)cout<<c[i+1]<<' ';
}
