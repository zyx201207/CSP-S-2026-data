#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	char b;
}s[200005];
int n;
int lon;
int ans;
int head=1;
int tail;
int lon1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	tail=n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
		lon+=s[i].a;
	}
	if(lon%2==0)
		lon1=lon/2;
	else
		lon1=(lon-1)/2;
	while(lon1>0)
	{
		if(min(s[head].a,s[tail].a)<=lon1)
		{
			if(s[head].a>s[tail].a)
			{
				lon1-=s[tail].a;
				if(s[head].b!=s[tail].b)
				{
					ans+=s[tail].a;
					s[head].a-=s[tail].a;
					tail--;
				}
				else
				{
					s[head].a-=s[tail].a;
					tail--;
				}		
			}
			else if(s[head].a<s[tail].a)
			{
				lon1-=s[head].a;
				if(s[head].b!=s[tail].b)
				{
					ans+=s[head].a;
					s[tail].a-=s[head].a;
					head++;
				}
				else
				{
					s[tail].a-=s[head].a;
					head++;
				}		
			}
			else
			{
				lon1-=s[tail].a;
				if(s[head].b!=s[tail].b)
				{
					ans+=s[head].a;
					head++;
					tail--;
				}
				else
				{
					tail--;
					head++;
				}
			}
		}
		else
		{
			if(s[head].b!=s[tail].b)
				ans+=lon1;
			lon1=0;		
		}							
	}
	cout<<ans;
	return 0;
}
