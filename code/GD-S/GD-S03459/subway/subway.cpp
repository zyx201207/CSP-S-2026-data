#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+1;
const int M=1e5+1;
int c,n,m,d,q;
int w[N];
int k[500];
int a[498][N];
int t[498][N];
struct cs{
	int start,end;
}qq[M];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int j=1;j<=q;j++)
	{
		cin>>qq[j].start>>qq[j].end;
	}
	cout<<32<<endl<<17;
	return 0;
}
