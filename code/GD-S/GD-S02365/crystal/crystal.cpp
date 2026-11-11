#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool cmp(int a,int b)
{
	return a<b;
}
int a[500005];
int b[500005];
int qian[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);

	for(int i=1;i<n;i++)
	{
		b[i]=abs(a[i+1]-a[i]);
		qian[i]=qian[i-1]+b[i]*i;
	}
	
	int i=1;
	while(m>=qian[i] && i<n)
	{
		i++;
	}
	cout<<i;
	return 0;
} 
