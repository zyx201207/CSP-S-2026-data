#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0,cnt=0,pa,m,f=0,k,lcx,lc,lc2,ans=0,ans2=0;
char lcy;
struct ll
{
	int x;
	char y;
}a[200010],b[200010],t;
stack<ll> stk;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		sum+=a[i].x;
	}
	pa=sum+1;
	pa/=2;
	for(int i=1;i<=n;i++)
	{
		if(cnt+a[i].x>=pa&&!f)
		{
			f=1;
			b[++m].x=pa-(cnt+(sum%2));
			b[m].y=a[i].y;
			b[++m].x=cnt+a[i].x-pa;
			b[m].y=a[i].y;
		}
		else
		{
			b[++m].x=a[i].x;
			b[m].y=a[i].y;
		}
		cnt+=a[i].x;
	}
	sum=0;
	for(int i=1;i<=m;i++)
	{
		sum+=b[i].x;
	}
	pa=sum/2;
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		cnt+=b[i].x;
		if(cnt<=pa)
		{
			stk.push(b[i]);
		}
		else
		{
			lc=lc2=0;
			while(1)
			{
				if(stk.top().x==0)
				{
					stk.pop();
					continue;
				}
				if(lc+stk.top().x>=b[i].x)
				{
					if(stk.top().y==b[i].y)
					{
						lc2+=b[i].x-lc;
					}
					break;
				}
				if(stk.top().y==b[i].y)
				{
					lc2+=stk.top().x;
				}
				lc+=stk.top().x;
				stk.pop();
			}
			int hf=b[i].x-lc;
			t=stk.top();
			stk.pop();
			t.x-=hf;
			stk.push(t);
			ans+=b[i].x;
			ans2+=lc2;
		}
	}
	cout<<ans-ans2;
	return 0;
}

