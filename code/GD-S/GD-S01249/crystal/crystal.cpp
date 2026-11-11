#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
typedef long long ll;
const int MAXN=500005;
ll n,m,a[MAXN],maxn=-1,l=0,x=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			x=0;
			for(int o=i;o<j;o++)
			{
				x=x+(a[j]-a[o]);
				l=j-i+1;
			}
			if(x<=m)
			{
				maxn=max(l,maxn);
			}
		}
	}
	cout<<maxn;
	return 0;
}
