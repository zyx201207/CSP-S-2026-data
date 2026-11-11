#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N=5e5+10;
ll n,m;
ll a[N],s[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		stack<ll> s1,s2;
		for(int i=k;i<=n;i++)
		{
			bool f=true;
			while(!s1.empty())
			{
				if(s1.top()==a[i])
				{
					f=false;
					break;
				}
				s2.push(s1.top());
				s1.pop();
			}
			if(f)
			{
				while(!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
				s1.push(a[i]);
			}
			else
			{
				while(!s2.empty()) s2.pop();
			}
		}
		while(!s1.empty())
		{
			s[s1.top()]++;
			s1.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}

