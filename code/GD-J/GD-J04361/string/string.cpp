#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+20;
struct edge{
	ll a;
	string s;
}e[N];
ll n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll lon=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		string s;
		cin>>a>>s;
		e[i].a=a;
		e[i].s=s;
		lon+=a;
	}
	int cnt=n,i=1;
	ll ans=0;
	int cc=0,cn=0;
	while(cc+cn<lon)
	{
		if(e[cnt].a<=0)
		{
			cnt--;
		}
		if(e[i].a<=0)
		{
			i++;
		}
		if(i==cnt)
		{
			break;
		}
		else if(i>cnt)
		{
			break;
		}
		if(e[i].s==e[cnt].s )
		{
			if(e[i].a<=e[cnt].a )
			{
				cc+=e[i].a;
				
				e[cnt].a-=e[i].a;
				cn+=e[i].a;
				i++;
			}
			else
			{
				e[i].a-=e[cnt].a;
				cc+=e[cnt].a;
				cn+=e[cnt].a;
				cnt--;
			}
			continue;
		}
		if(e[i].s != e[cnt].s )
		{	
			if(e[i].a==e[cnt].a)
			{
				ans+=e[cnt].a;
				cc+=e[i].a;
				cn+=e[cnt].a;
				cnt--;
				i++;
			}
			if(e[i].a > e[cnt].a )
			{
				e[i].a=e[i].a-e[cnt].a;cn+=e[cnt].a;
				ans+=e[cnt].a;
				cc+=e[cnt].a;
				cnt--;
			}
			else 
			{
				e[cnt].a=e[cnt].a-e[i].a;
				ans+=e[i].a;
				cn+=e[i].a;cc+=e[i].a;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
