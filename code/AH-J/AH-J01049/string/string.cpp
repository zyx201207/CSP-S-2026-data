#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
struct NODE
{
	ll a;
	char c;
};
NODE s[1000005];
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	char dz;
	ll ds=0,qh;
	ll ans=0;
	for(int i=1;n-i+1>=i;i++)
	{
		if(ds&&qh==1)
		{
			if(ds>s[n-i+1].a)
			{
				while(n--)
				{
					if(s[n-i+1].c==dz) ds-=s[n-i+1].a;
					else ds-=s[n-i+1].a,ans+=max(ds,s[n-i+1].a);
					if(ds<=0) {n++; ans+=ds; s[n-i+1].a=(-1*ds); break;}
				}
			}
			else 
			{
				if(s[n-i+1].c==dz) s[n-i+1].a-=ds;
				else s[n-i+1].a-=ds,ans+=max(ds,s[n-i+1].a);
		    }
		}
		if(ds&&qh==0)
		{
			if(ds>s[i].a)
			{
				while(n--)
				{
					if(s[i].c==dz) ds-=s[i].a;
					else ds-=s[i].a,ans+=max(ds,s[i].a);
					if(ds<=0) {n++; ans+=ds; s[i].a=(-1*ds); break;}
				}
			}
			else
			{
				if(s[i].c==dz) s[i].a-=ds;
				else s[i].a-=ds,ans+=max(ds,s[i].a);
			}
		}
		if(s[i].c==s[n-i+1].c)
		{
			if(s[i].a>=s[n-i+1].a) dz=s[i].c,ds=s[i].a-s[n-i+1].a,qh=1;
			if(s[i].a<=s[n-i+1].a) dz=s[n-i+1].c,ds=s[n-i+1].a-s[i].a,qh=0;
		}
		if(s[i].c!=s[n-i+1].c)
		{
			if(s[i].a>=s[n-i+1].a) dz=s[i].c,ds=s[i].a-s[n-i+1].a,qh=1,ans+=s[n-i+1].a;
			if(s[i].a<=s[n-i+1].a) dz=s[n-i+1].c,ds=s[n-i+1].a-s[i].a,qh=0,ans+=s[i].a;
		}
	}
	cout<<ans;
	return 0;
}
