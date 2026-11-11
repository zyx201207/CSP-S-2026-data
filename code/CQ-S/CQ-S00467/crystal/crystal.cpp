#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],ans,tot=0,b[205];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]*(j-i+1)-s[j]+s[i]<=m) ans=max(ans,j-i+1);
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++) 
		{
			while(-(a[tot+1]-a[tot])>m) tot++;
			if(s[tot+1]-s[tot]>m) tot++;
			if(a[i]*(i-tot)-(s[i])+(s[tot])<=m) ans=max(ans,i-tot);
		}
		cout<<ans;
	}
	return 0;
 } 
 /*
5 10
-1000 1 2 5 6
tot   |
 */
