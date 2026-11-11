#include<bits/stdc++.h>
using namespace std;;
typedef long long ll;
const int N = 2e5+7;
ll len,l,r,cnt,n,ans;
ll w[N],o[N];
char k[N],f[N];
int main(void)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>f[i];
		len+=w[i];
	}
	if(len%2==1)
	{
		int s=0;
		
		for(int i=1;i<=n;i++)
		{
			s+=w[i];
			if(s>=len/2+1)
			{
				o[i]--;
				len--;
				break;
			}
		}
	}
	ll s=0;
	ll id=0;
	bool flag=1;
	for(ll i=1;i<=n;i++)
	{
		s+=w[i];
		if(s>len/2&&flag)
		{
			flag=0;
			o[++id]=w[i]-s+len/2;
			k[id]=f[i];
			o[++id]=s-len/2;
			k[id]=f[i];
			
		}
		else 
		{
			o[++id]=w[i];
			k[id]=f[i];
		}
	}
	n=id;
	l=1,r=n;
	while(l<=r)
	{
		ll s1=o[l],s2=o[r];
		char op1=k[l],op2=k[r];
		if(s1>s2)
		{
			if(op1!=op2)ans+=s2;
			r--;
			o[l]-=s2;
		}
		if(s1==s2)
		{
			if(op1!=op2)ans+=s1;
			l++,r--;
		}
		if(s1<s2)
		{
			if(op1!=op2)ans+=s1;
			l++;
			o[r]-=s1;
		}
		
	}
	cout<<ans;
	return 0;
}
