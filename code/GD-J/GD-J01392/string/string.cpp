#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int a[N],b[N]; 
struct nd{int l,z;}s1[N],s2[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
	}
	int len=0;
	for(int i=1;i<=n;i++)len+=a[i];
	int now=0;int l1=0,l2=0;
	for(int i=1;i<=n;i++)
	{
		if(now+a[i]>len/2)break;
		s1[++l1]={a[i],b[i]};
		now+=a[i];
	}
	now=len;
	for(int i=n;i>=1;i--)
	{
		if(now-a[i]<=len/2)break;
		s2[++l2]={a[i],b[i]};
		now-=a[i];
	}
	now=0;
	for(int i=1;i<=n;i++)
	{
		if(now+a[i]>len/2)
		{
			if(now<len/2)
			{
				s1[++l1]={len/2-now,b[i]};
			}
			if(now+a[i]>(len+1)/2)
			{
				s2[++l2]={now+a[i]-(len+1)/2,b[i]};
			}
			break;
		}
		now+=a[i]; 
	}
	int ans=0;
	for(int i=1,j=1;i<=l1&&j<=l2;)
	{
		if(s1[i].l==s2[j].l)
		{
			ans+=s1[i].l*(s1[i].z!=s2[j].z);
			i++;j++;
		}
		else
		{
			if(s1[i].l<s2[j].l)
			{
				ans+=s1[i].l*(s1[i].z!=s2[j].z);
				s2[j].l-=s1[i].l;i++;
			}
			else
			{
				ans+=s2[j].l*(s1[i].z!=s2[j].z);
				s1[i].l-=s2[j].l;j++;
			}
		}
	}
	cout<<ans;return 0;
}
