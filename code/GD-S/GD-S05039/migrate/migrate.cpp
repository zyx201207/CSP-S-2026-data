#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t;
int n;
ll d,x[N],ji[N];
int ans=0;
void dfs(int q)
{
	if(q==n)return;
	for(int i=q+1;i<=n;i++)
	{
		if(x[i]-x[q]<=d)
		{
			ji[i]++;
			dfs(i);
		}
		else break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	int ans=0;
	while(t--)
	{
		ans=0;
		memset(ji,0,sizeof ji);
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++)
			dfs(i);
		for(int i=1;i<=n;i++)
		{
			if(ji[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}




