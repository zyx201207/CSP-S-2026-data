#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int N=5e5+5;
ll a[N],pre[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,mx=0;
    ull m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	ull maxx;
	for(int i=1;i<=n;i++)
	{
		maxx=a[i]*i;
		if(maxx-pre[i]<=m)
			mx=max(mx,i);
	}
	cout<<mx;
	return 0;
}
