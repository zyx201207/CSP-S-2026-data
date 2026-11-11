#include<bits/stdc++.h>
using namespace std;
long long w[5005];
long long a[5005];
long long t[5005];
bool mp[5005][5005];
struct P
{
	int kt,tt;
}sj[5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=2k;j++)
		{
			cin>>a[j];
			cin>>t[j];
		}
		for(int j=2;j<=k;j++)
		{
			mp[a[j-1]][a[j]]=1;
			mp[a[j]][a[j]-1]=1;
		}
	}
	int sum=0;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		sum=sum+w[x]+w[y];
	}
	return 0;
} 
