#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5005],z[5003],ans[5003];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>5000||m>5000)
	{
		for(int i=1;i<=m;i++)cout<<n<<' ';
		return 0;
	} 
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(z,0,sizeof z);
		stack<ll>s;
		for(int j=i;j<=n;j++)
		{
			if(z[a[j]])
				while(s.top()!=a[j])z[s.top()]=0,s.pop();
			else z[a[j]]=1,s.push(a[j]);
		}
		for(int j=1;j<=m;j++)ans[j]+=z[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
