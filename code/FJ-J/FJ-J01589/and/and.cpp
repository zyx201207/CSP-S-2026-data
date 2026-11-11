#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
int a[N],b[N],num,mem;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	mem=n;
	for(int i=30;i>=0;i--)
	{
		int now=1<<i;
		num=0;
		for(int j=1;j<=mem;j++)
		{
			if(a[j]&now)b[++num]=a[j];
		}
		if(num>=m)
		{
			for(int j=1;j<=num;j++)a[j]=b[j];
			mem=num;
		}
	}
	int ans=a[1];
	for(int i=2;i<=mem;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

