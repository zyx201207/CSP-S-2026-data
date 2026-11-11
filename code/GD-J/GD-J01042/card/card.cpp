#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],g[300005];
stack<long long> k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			while(b[a[j]]==2) b[k.top()]--,k.pop();
			k.push(a[j]);
		}
		while(!k.empty())
		{
			if(b[k.top()]!=0) g[k.top()]++,b[k.top()]=0;
			k.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<g[i]<<" ";
	return 0;
}
