#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
string s;
int sum[200005];

long long ans=0;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		char c;
		int a;
		cin>>a>>c;
		if(c==s.back())
		{
			sum[--i]+=a;
			--n;
		}
		else
		{
			sum[i]=a;
			s.push_back(c);
		}
	}
	
	int l=1,r=n;
	while(l<=r)
	{
		if(sum[r]-sum[l]<=0)
		{
			if(s[l-1]!=s[r-1])
			{
				ans+=sum[r];
			}
			sum[l]-=sum[r];
			sum[r]=0;
			r--;
			if(sum[l]==0)
			{
				l++;
			}
			
		}
		else
		{
			if(s[l-1]!=s[r-1])
			{
				ans+=sum[l];
			}
			sum[r]-=sum[l];
			l++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
/*
 * 
13
1a
1b
1c
1d
1e
3a
2b
2f
1i
1j
1k
1m
1n
*/
