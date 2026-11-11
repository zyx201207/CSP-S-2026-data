#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
const int maxm = 1e5+5;
int n,m,c,d,q;
int w[maxm]={},k[maxm]={};
int a[501][maxn]={},t[505][maxn]={};
int x[maxm]={},y[maxm]={};


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i = 1;i <= q;i++) cin>>x[i]>>y[i];
	for(int i = 1;i <= q;i++)
	{
		long long ans=0;
		ans+=w[x[i]]+t[x[i]][x[i]];
		for(int j = x[i]+1;j < y[i];j++) ans+=t[i][i+1]+t[i+1][i+1];
		ans+=w[y[i]];
		cout<<ans<<endl;
	}
	return 0;
}
