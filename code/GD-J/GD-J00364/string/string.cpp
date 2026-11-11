#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,cnt,ans,pos=1;
struct node
{
	int a;
	char c;
}s[400005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		cnt+=s[i].a;
	}
	for(int i=1;pos<=cnt/2;i++)
	{
		int x=min(s[i].a,s[n-i+1].a);
		int y=max(s[i].a,s[n-i+1].a);
		if(s[i].c!=s[n-i+1].c) ans+=x;
		bool f=s[i].a>s[n-i+1].a?1:0;
		int j=i,q;
		while(x<y)
		{
			if(f)
				if(s[n-j].c!=s[i].c)
				{
					q=min(y-x,s[n-j].a);
					ans+=q;
					x+=q;
				}
			else
				if(s[j].c!=s[n-i+1].c)
				{
					q=min(y-x,s[j].a);
					ans+=q;
					x+=q;
				}
		}
		pos+=y;
	}
	cout<<ans;
	return 0;
}
