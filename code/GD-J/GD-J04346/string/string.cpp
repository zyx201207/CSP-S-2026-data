#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+10;

ll a[N];
char b[N]; 

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	ll x=1,y=n,ans=0;
	
	while(x<y)
	{
		if(b[x]!=b[y])
		{
			if(a[x]==a[y])
			{
				ans=ans+a[x];
				x++;
				y--;
			}
			else if(a[x]<a[y])
			{
				ans+=a[y]-a[x];
				a[y]=a[y]-a[x];
				x++;
			}
			else
			{
				ans+=a[x]-a[y];
				a[x]=a[x]-a[y];
				y--;
			}
		}
		else
		{
			if(a[x]==a[y])
			{
				x++;
				y--;
			}
			else if(a[x]<a[y])
			{
				a[y]=a[y]-a[x];
				x++;
			}
			else
			{
				a[x]=a[x]-a[y];
				y--;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

