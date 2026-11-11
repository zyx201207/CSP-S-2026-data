#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,lo,a[200005],su=1,m;
string s,s1,x[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i]>>x[i];
	while(1)
	{
		int cnt1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%10==0) cnt1++;
		}
		if(cnt1==n)
		{
			su*=10;			
			for(int i=1;i<=n;i++)
			{
				a[i]/=10;
			}
		}
		else break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++) s+=x[i];
	}
//	cout<<s<<endl;
	lo=s.size()-1;
//	cout<<lo<<endl;
	for(int i=0;i<=lo/2;i++)
	{
		if(s[i]!=s[lo-i]) ans++;
//		cout<<i<<" "<<lo-i<<endl;
	}
//	cout<<endl;
	cout<<ans*su;
	return 0;
}
