#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
	long long a;
	char c;
}s[N];
long long n,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(s[l].c!=s[r].c)
		{
			if(s[l].a>s[r].a)
			{
				ans+=s[r].a;
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
			else if(s[l].a<s[r].a)
			{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
			}
			else
			{
				ans+=s[l].a;
				s[l].a=0;
				s[r].a=0;
				l++;
				r--;
			}
		}
		else
		{
			if(s[l].a>s[r].a)
			{
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
			else if(s[l].a<s[r].a)
			{
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
			}
			else
			{
				s[l].a=0;
				s[r].a=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans; 
	return 0;
}
