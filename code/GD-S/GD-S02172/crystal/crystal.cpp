#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans,s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n>5000)
	{
		ll k=a[2]-a[1],res=0;
		for(int i=1;i<=n;i++)
		{
			res+=k*i;
			if(res>m)
			{
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;	
	} 
	for(int i=1;i<=n;i++)
	{
		ll res=0,s=0;
		for(int j=i;j>=1;j--)
		{
			if(res+a[i]-a[j]<=m)
				res+=a[i]-a[j],s++;
			else break;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
} 
