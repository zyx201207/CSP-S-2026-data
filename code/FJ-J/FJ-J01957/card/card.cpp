#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[500010];
int ans[300010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		int mn[500010];
		string s="";
		int k=1;
		for(int i=j;i<=n;i++)
		{
			if(a[i]==0) continue;
			char c=a[i]-'0';
			if(s.find(c)==-1)
			{
				mn[k]=a[i];
				k++;
				s+=c;
			}
			else
			{
				int x=a[i];
				k=s.find(c);
				for(int l=s.find(c);l<=i;l++,k++)
				{
					a[l]=0;
					mn[k]=0;
				}
				k=s.find(c);
				mn[k]=x;
				k++;
				string t="";
				for(int l=0;l<=s.find(c);l++) t=t+s[i];
				s=t;
			}
		}
		for(int i=1;i<=k;i++)
		{
			ans[mn[i]]++;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
