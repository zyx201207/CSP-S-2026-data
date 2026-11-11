#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],minn,add,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	minn=a[1];
	while(m>0)
	{
		add=0;
		for(int i=1;i<=n;i++) if(a[i]==minn) add++;
		if(m>=add) 
		{
			m-=add;
			for(int i=1;i<=add;i++) a[i]++;
			minn++;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[i+1]) ans++;
				else break;
			}
			cout<<ans+1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]) ans++;
		else break;
	}
	cout<<ans+1;
	return 0;
}
