#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans,cntl,cntr;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	cntl=1;
	cntr=n;
	long long s;
	while(cntl<cntr)
	{
		if(c[cntl]!=c[cntr])
		{
			ans+=min(a[cntl],a[cntr]);
		}
		if(a[cntl]<a[cntr])
		{
			s=a[cntr]-a[cntl];
			cntl++;
			while(s>0&&cntl<cntr)
			{
				if(c[cntl]!=c[cntr])
				{
					ans+=min(s,a[cntl]);
				}
				if(s>=a[cntl])
				{
					s-=a[cntl];
					cntl++;
				}
				else
				{
					a[cntl]-=s;
					s=0;
				}
			}
			cntr--;
		}
		else if(a[cntl]>a[cntr])
		{
			s=a[cntl]-a[cntr];
			cntr--;
			while(s>0&&cntl<cntr)
			{
				if(c[cntl]!=c[cntr])
				{
					ans+=min(s,a[cntr]);
				}
				if(s>=a[cntr])
				{
					s-=a[cntr];
					cntr--;
				}
				else
				{
					a[cntr]-=s;
					s=0;
				}
			}
			cntl++;
		}
		else
		{
			cntl++;
			cntr--;
		}
	}
	cout<<ans;
	return 0;
}
