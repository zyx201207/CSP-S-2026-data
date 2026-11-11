#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
const ll M = 3e5 + 5;
ll n,m,a[N],t[M],d[M],ans[M],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		sum-=t[a[i]];
		//cout<<t[1]<<' ';
		ans[a[i]]=max(ans[a[i]],i-sum);
		t[a[i]]=i-sum;
		if(d[a[i]]!=i) sum+=i-sum;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
