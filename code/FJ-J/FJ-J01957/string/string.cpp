#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int sum=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		string t="";
		sum+=a[i];
		if(sum>5e8)
		{
			cout<<0;
		}
		t=t+c[i];
		for(int j=2;j<=a[i];j*=2)
		{
			t+=t;
			if(j*2>a[i] && j!=a[i])
			{
				for(int k=i;k<=a[i];k++)
				{
					t+=c[i];
				}
			}
		}
		s=s+t; 	
	}
	int ans=0;
	for(int l=0,r=s.size()-1;l<=r;l++,r--)
	{
		if(s[l]!=s[r]) ans++;
	}
	cout<<ans;
	return 0;
}
