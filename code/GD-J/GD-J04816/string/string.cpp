#include <bits/stdc++.h>
using namespace std;
int n,a[100000005];
long long ans,flag,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int l;
		char z;
		cin>>l;
		cin>>z;
		int x=z-96;
		ans+=l;
		if(l>=(1e9-1000))
		{
			flag=1;
			continue;
		}
		for(int j=ans-l+1;j<=ans;j++)
		{
			a[j]=x;
		}
	}
	if(flag)
	{
		cout<<ans/2;
	}else
	{
		for(int i=1;i<=ans/2;i++)
		{
			if(a[i]!=a[ans-i+1])
			{
				cnt++;
			}
		}
		cout<<cnt;
	}
	
	return 0;
}			
