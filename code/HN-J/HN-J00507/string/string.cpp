#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,s[1000005],t[1000005],a[1000005],n;
char c[1000005];
int ch(int x)
{
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=l+r>>1;
		if(s[mid]<=x)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return l;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		s[i]=t[i-1]+1;
		t[i]=t[i-1]+a[i];
	}
	int midd=0; 
	for(int i=1;i<=n;i++)
	{
		if(s[i]<=t[n]/2+bool(t[n]%2)&&t[i]>=t[n]/2+1)
		{
			midd=i;
			break;
		}
		if(t[n]%2==0&&s[i]==t[n]/2+1)
		{
			midd=i;
			break;
		}
	}
	int last=t[n];
	if((t[n]%2==0&&s[midd]!=t[n]/2+1)||t[n]%2==1)
	{
		int st=last-t[midd]+1,en=last-s[midd]+1;
		if(en>t[midd])
		{
			if(c[midd+1]!=c[midd])
			{
				ans+=en-s[midd+1]+1;
			}
		}
//		if(st<s[midd])
//		{
//			if(c[midd-1]!=c[midd])
//			{
//				ans+=t[midd-1]-st+1;
//			}
//		}
	}
	for(int i=1;i<midd;i++)
	{
		int st=last-t[i]+1,en=last-s[i]+1;
		int sid=ch(st);
		int eid=ch(en);
		if(sid==eid)
		{
			if(c[sid]!=c[i])
			{
				ans+=a[i];
			}
		}
		else
		{
			for(int j=sid+1;j<=eid-1;j++)
			{
				if(c[j]!=c[i])
				{
					ans+=a[j];
				}
			}
			if(c[sid]!=c[i])
			{
				ans+=t[sid]-st+1;
			}
			if(c[eid]!=c[i])
			{
				ans+=en-s[eid]+1;
			}
		}
	}
	cout<<ans; 
	return 0;
}



//T2怎么是分块（8级hyw） ,好像想复杂了，不管了，能过就行。 
//9:10AC
//9:20 写错了 
//9:28二分多次使用不清空
//但是还没过 
//T1+T2 1h21min我真的服了 
