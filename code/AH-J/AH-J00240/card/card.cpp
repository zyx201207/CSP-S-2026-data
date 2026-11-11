#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],vis[300005],f[300005];
stack <int> s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			vis[a[j]]++;
			if(vis[a[j]]>1)
			{
				while(!s.empty() && vis[a[j]]>1)
				{
					int x=s.top();
					vis[x]--;
					s.pop();
				}
			}
			s.push(a[j]);
		}
		while(!s.empty())
		{
			int x=s.top();
			f[x]++;
			vis[x]--;
			s.pop();
		}
	}
	for(int i=1; i<=m; i++)
		cout<<f[i]<<" ";
    return 0;
}
