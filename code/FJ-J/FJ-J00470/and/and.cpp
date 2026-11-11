#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string a[200005];
ll b[200005],c[200005],q[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(b,b+n-1);
	q[0]=b[0];
	ll maxn=q[0];
	for(int u=1;u<n;u++)
	{
		q[u]=q[u-1]&b[u];
	}
	for(int i=0;i+m<n;i++)
	{
		maxn=max(q[i+m],maxn);
	}
	cout<<maxn;
	return 0;
}
