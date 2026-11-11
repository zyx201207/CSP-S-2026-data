#include <bits/stdc++.h>
using namespace std;

struct S
{
	long long id,a;
	char c;
}s[2000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0,cnt =0;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		int a;char c;
		cin>>a>>c;
		s[i]={len+1,a,c};
		len+=a;
	}
	long long l = 1,r = n;
	while(l<r)
	{
		if(s[l].a<s[r].a)
		{
			if(s[l].c!=s[r].c)cnt+=s[l].a;
			s[r].a-=s[l].a;
			l++;
		}
		else
		{
			if(s[l].c!=s[r].c)cnt+=s[r].a;
			s[l].a-=s[r].a;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
