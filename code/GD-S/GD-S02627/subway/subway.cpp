#include<bits/stdc++.h>
using namespace std;
struct print
{
	long long k;
	long long a[401],t[401];
};print h[301];
long long c,n,m,d,q,w[201],x[201],y[201];
bool f[201][201];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>h[i].k;
		for(int j=1;j<=h[i].k;j++)
		{
			cin>>h[i].a[j]>>h[i].t[j];
			f[h[i].a[j]][i]=h[i].t[j];
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++)
	{
		cout<<w[x[i]]+f[x[i]][1]+f[y[i]][1]+w[y[i]]<<endl;
	}
	return 0; 
}

