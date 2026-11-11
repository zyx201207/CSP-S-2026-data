#include<bits/stdc++.h>
using namespace std;
struct sg
{
	long long a;
	char c;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].c;
	unsigned long long cnt=0;
	for(int i=1,j=n;i<j;)
	{
		if(s[i].c!=s[j].c)
			cnt+=min(s[i].a,s[j].a);
		if(s[i].a>s[j].a)
		{
			s[i].a-=s[j].a;
			j--;
			continue;
		}
		if(s[i].a<s[j].a)
		{
			s[j].a-=s[i].a;
			i++;
			continue;
		}
		if(s[i].a==s[j].a) i++,j--;
	}
	cout<<cnt;
	return 0;
}
