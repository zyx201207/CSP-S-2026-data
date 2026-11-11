#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char c;
};
node e[200010],r1[200010],r2[200010];
long long cnt,mid,as,i,r,s[200010];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>e[i].a>>e[i].c;
		s[i]=s[i-1]+e[i].a;
	}
	if(n<=20000&&s[n]<100000000)
	{
		string str="",s="";
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=e[i].a;j++) 
			{
				str+=e[i].c;
				s=e[i].c+s;
			}
		}
		if(str==s) cout<<0;
		else
		{
			int len=s.size();
			int ans=0;
			for(int i=0;i<len/2;i++)
			{
				if(s[i]!=str[i]) ans++;
			}
			cout<<ans;
		}
	}
	else
	{
		mid=s[n]/2;
		r=n;
		int t=lower_bound(s+1,s+n+1,mid)-s;
		if(e[1].a>=mid)
		{
			long long b=0;
			for(int i=2;i<=n;i++)
			{
				if(e[i].c==e[1].c) b+=e[i].a;
			}
			if(s[n]%2!=0) cout<<s[n]-mid-b-1;
			else cout<<s[n]-mid-b;
			return 0;
		}
		i=1;
		while(cnt+e[i].a<=mid)
		{
			cnt+=e[i].a;
			while(e[i].a)
			{
				if(e[i].c!=e[r].c)
				{
					as+=min(e[i].a,e[r].a);
					if(e[i].a>=e[r].a) 
					{
						 e[i].a-=e[r].a;
						 r--;
					}
					else e[r].a-=e[i].a;
				}
				else
				{
					if(e[i].a>=e[r].a) 
					{
						 e[i].a-=e[r].a;
						 r--;
					}
					else e[r].a-=e[i].a;
				}
			}
				i++;
		}
		long long b=0;
		for(i=t+1;i<=r;i++)
		{
			if(e[i].c==e[t].c) b+=e[i].a;
		}
		cout<<as+b;
	}
	
}
