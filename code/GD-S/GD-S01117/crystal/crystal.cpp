#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,Madoka=0x3f,Homora=0x7fffffff;

int n;
ll m,a[N],s[N];

bool check(int l,int r)
{
	ll cost=(r-l+1)*a[r]-(s[r]-s[l-1]);
	return cost<=m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	ll ans=1;
	bool flag=0;
	for(int i=n;i>=1;i--)
	{
		for(int l=1;l<=n-i+1;l++)
		{
			int r=l+i-1;
			if(check(l,r))
			{
				ans=i;
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	
	cout<<ans<<endl;
}
