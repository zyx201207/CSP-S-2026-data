#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<ll>a(500010),s(300010),v(300010,0),vr(300010,0);
	ll n,m;
	stack<ll>t;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		v=vr;
		for(int j=i;j<n;j++)
		{
			if(v[a[j]]==0)
			{
				t.push(a[j]);
				v[a[j]]=1;
			}
			else
			{
				while(t.top()!=a[j])
				{
					v[t.top()]=0;
					t.pop();
				}
			}
		}

		while(!t.empty())
		{
			int x=t.top();
			s[x]++;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
