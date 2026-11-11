#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005];
bool h[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(h,0,sizeof(h));
		stack<int> s;
		for(int j=i;j<=n;j++)
		{
			if(!h[a[j]])
			{
				h[a[j]]=1;
				s.push(a[j]);
				continue;
			}
			while(s.top()!=a[j])
			{
				int fr=s.top();
				h[fr]=0;
				s.pop();
			}
		}
		for(int j=1;j<=m;j++)
			if(h[j])
				sum[j]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
