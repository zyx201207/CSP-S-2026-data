#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll andw[31];
bool cmp(ll a,ll b)
{
	return a>b;
}
ll andd(ll a,ll b)
{
	string a1="",b1="",c1="";
	while(1)
	{
		a1+=(a%2+'0');
		a/=2;
		if(a==0)
		break;
	}
	while(1)
	{
		b1+=(b%2+'0');
		b/=2;
		if(b==0)
		break;
	}
	for(int i=0;i<min(a1.size(),b1.size());i++)
	{
		if(a1[i]=='1' && b1[i]=='1')
			c1+='1';
		else
			c1+='0';
	}
	ll ans=0,c=0;
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]=='1')
			ans+=andw[c];
		c++;
	}
	return ans;
}
const ll N=10+2*1e5;
ll n,m,a[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	andw[0]=1;
	for(int i=1;i<=32;i++)
		andw[i]=andw[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)
		ans=andd(ans,a[i]);
	cout<<ans;
	return 0;
}
