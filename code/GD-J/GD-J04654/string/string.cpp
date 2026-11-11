#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+10;
ll n,ans,t[N],cnt,l=1,p=1,sum;
char c[N];
struct node{
	ll s,e;
	char c;
}a[N];
string s;
ll chk(ll s,ll e,char c)
{
	ll ss=0;
	while(a[p].s>=s&&a[p].s<=e&&a[p].e>=s&&a[p].e<=e)
	{
		if(a[p].c!=c)
			ss+=a[p].e-a[p].s+1;
		p--;
	}
	if(a[p].s>=s&&a[p].s<=e)
	{
		if(a[p].c!=c)
			ss+=min(a[p].e,e)-a[p].s+1;
		a[p].s=e+1;
	}
	return ss;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
//	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		cin>>c[i];
		sum+=t[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(l<=(sum+1)/2)
		{
			a[++cnt].s=max((sum+1)/2,sum-l-t[i]+2);
			a[cnt].e=sum-l+1;
			a[cnt].c=c[i];
			p=cnt;
		}
		if(l+t[i]-1>(sum+1)/2)
		{
			ans+=chk(l,l+t[i]-1,c[i]);
		}
		l+=t[i];
	}
	cout<<ans;
	return 0;
}
