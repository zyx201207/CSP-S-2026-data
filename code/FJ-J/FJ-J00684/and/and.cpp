#include <bits/stdc++.h>
using namespace std;
#define P 200010
typedef long long ll;
ll a[P];
ll b[40] = {0};
ll f(ll qa)
{
	ll o = 1;
	while(qa>1)
	{
		if(qa%2==1)
		{
			o++;
		} 
		qa = qa/2;
	}
	return o;
}
ll ff(ll aq)
{
	ll sp = 1;
	for(int qz = 1;qz<aq;qz++)
	{
		sp = sp*2+1;
	}
	return sp;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	ll sa;
	ll q,w = 0;
	cin>>n>>m;
	ll s = 0;
	if(m==1)
	{
		for(ll i = 1;i<=m;i++)
		{
			cin>>q;
			if(w<q)
			{
				w = q;
			}
		}
		cout<<w<<endl;
		return 0;
	}
	if(m==n)
	{
		cin>>w>>q;
		s = w&q;
		for(ll i = 3;i<=m;i++)
		{
			cin>>q;
			s = s&q;
		}
		cout<<s<<endl;
		return 0;
	}
	if(m==2)
	{
		for(ll i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(ll i = 1;i<=n;i++)
		{
			for(ll j = i+1;j<=n;j++)
			{
				sa = a[i]&a[j];
				if(sa>s)
				{
					s = sa;
				}
			}
		}
		cout<<s<<endl;
		return 0;
	}
	for(ll i = 1;i<=n;i++)
	{
		cin>>a[i];
		b[f(a[i])]++;
	}
	for(ll i = 33;i>=1;i--)
	{
		m = m-b[i];
		if(m<=0)
		{
			cout<<ff(i)<<endl;
			return 0;
		}
	}
	return 0;
}

