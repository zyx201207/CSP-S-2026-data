#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=0,m=0;
ll a[1000005];
ll ans=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ans=1;ans<=m;m--)
	{
//		cout<<"i:"<<i<<endl;
		if(a[ans]<a[ans+1])
		{
			a[ans]=a[ans]+1;
			if(a[ans-1]!=a[ans])
			{
				a[ans-1]=a[ans-1]+1;
			}
		}
		else
		{
			ans++;
		}
	}
	cout<<ans+1;
	return 0;
}

