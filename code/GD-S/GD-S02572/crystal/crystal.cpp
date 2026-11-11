#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
long long b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) continue;
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(m<b[i])
		{
			cout<<i-1;
			break;
		}
	}
	return 0;
}

