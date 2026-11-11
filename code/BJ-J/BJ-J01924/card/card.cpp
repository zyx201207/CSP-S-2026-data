#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int cnt[M];
int p[M];
int main()
{
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
			cnt[a[i]]=i;
	}
	int o=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[i+1])
		{
			o=1;
			break;
		}
	if(o==0)
	{
		cnt[m]=n;
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<" ";
	}
	else
	{
		for(int i=1;i<=n;i++)
			p[a[i]]=i;
		p[m]=n;
		for(int i=1;i<=m;i++)
			cout<<p[i]<<" ";
	}
	return 0;
}
