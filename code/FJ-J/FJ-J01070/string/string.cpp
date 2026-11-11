#include<bits/stdc++.h>
using namespace std;
int n;
struct data
{
	int a;
	char c;
}s[200005];
long long ans,tot,p;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		tot+=s[i].a;
	}
	int l=1,r=n;
	while(p<=tot/2&&l<=r)
	{
		if(s[l].a==s[r].a)
		{
			if(s[l].c!=s[r].c)ans+=s[l].a;
			p+=s[l].a;
			l++;
			r--;
		}
		else if(s[l].a>s[r].a)
		{
			if(s[l].c!=s[r].c)ans+=s[r].a;
			s[l].a-=s[r].a;
			p+=s[r].a;
			r--;
		}
		else if(s[l].a<s[r].a)
		{
			if(s[l].c!=s[r].c)ans+=s[l].a;
			s[r].a-=s[l].a;
			p+=s[l].a;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
