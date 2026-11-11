#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5,inf=1e18;
ll n,m,q=(1<<25),w,e,r;
ll a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q=q&a[i];
		w=max(w,a[i]);
	}
	if(m==n)
	{
		cout<<q;
		return 0;
	}
	if(m==1)
	{
		cout<<w;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				r=max(r,a[i]&a[j]);
			}
		}
		cout<<r;
		return 0;
	}
	return 0;
}