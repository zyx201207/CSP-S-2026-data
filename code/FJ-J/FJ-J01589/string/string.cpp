#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int j=n,las=0;
	for(int i=1;i<=n&&i<j;i++)
	{
		int sum=0;
		while(sum<a[i])
		{
			if(las)sum+=las;
			else sum+=a[j];
			if(c[i]!=c[j])
			{
				if(las)ans+=las;
				else ans+=a[j];
			}
			las=0;
			if(sum<a[i])j--;
		}
		las=sum-a[i];
		if(c[i]!=c[j])ans-=las;
		if(las==0)j--;
	}
	cout<<ans;
	return 0;
}

