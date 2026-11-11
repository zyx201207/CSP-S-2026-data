#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char b;
};
node s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,i,ans=0,l=1,r;
	bool flag=0;
	cin>>n;
	r=n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		if(s[i].b!=s[1].b)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		cout<<min(s[1].a,s[2].a);
		return 0;
	}
	while(l<r)
	{
		if(s[l].b==s[r].b)
		{
			ans+=llabs(s[l].a-s[r].a);
		}
		else
		{
			ans+=max(s[l].a,s[r].a);
		}
		l++;
		r--;
		if(s[l-1].a>s[r+1].a)
		{
			s[l].a+=s[l-1].a-s[r+1].a;
		}
		if(s[l-1].a<s[r+1].a)
		{
			s[r].a+=s[r+1].a-s[l-1].a;
		}
	}
	cout<<ans;
}
