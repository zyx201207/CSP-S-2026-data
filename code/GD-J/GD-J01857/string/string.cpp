#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a1[N],a2[N];
char c1[N],c2[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	ll x;
	char c;
	cin>>x>>c;
	int idx=1;
	a1[1]=x;
	c1[1]=c;
	for(int i=2;i<=n;++i)
	{
		cin>>x>>c;
		if(c1[idx]==c)
		a1[idx]+=x;
		else 
		{
			idx++;
			a1[idx]=x;
			c1[idx]=c;
		}
	}
	for(int i=1;i<=idx;i++)
	{
		a2[i]=a1[idx-i+1];
		c2[i]=c1[idx-i+1];
	
	}
	ll ans=0;
	for(int i=1,j=1;i<=idx and j<=idx;)
	{
		if(c1[i]!=c2[j])
		{
			ans+=min(a1[i],a2[j]);
		}
		if(a1[i]>a2[j])
		a1[i]-=a2[j],j++;
		else if(a1[i]<a2[j])
		a2[j]-=a1[i],i++;
		else i++,j++;
	}
	cout<<ans/2;
}
