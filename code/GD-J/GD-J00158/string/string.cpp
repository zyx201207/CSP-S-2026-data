#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200009],i,curl,curr;
char s[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i]>>s[i];
	curl=1;
	curr=n;
	while(curl<curr)
	{
		if(s[curl]!=s[curr])
		{
			if(a[curl]>=a[curr])
			{
				ans+=a[curr];
				a[curl]-=a[curr];
				if(a[curl]==0)curl++;
				curr--;
			}
			else if(a[curr]>=a[curl])
			{
				ans+=a[curl];
				a[curr]-=a[curl];
				if(a[curr]==0)curr--;
				curl++;
			}
		}
		else if(s[curl]==s[curr])
		{
			if(a[curl]>=a[curr])
			{
				a[curl]-=a[curr];
				if(a[curl]==0)curl++;
				curr--;
			}
			else if(a[curr]>=a[curl])
			{
				a[curr]-=a[curl];
				if(a[curr]==0)curr--;
				curl++;
			}
		}
	}
	cout<<ans;
	return 0;
}
