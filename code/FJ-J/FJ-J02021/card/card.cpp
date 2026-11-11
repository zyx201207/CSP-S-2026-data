#include<bits/stdc++.h>
using namespace std;
int n,t,a[500005],k;
map<long long,long long>m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		m[a[i]]+=m[a[i-1]];
		m[a[i]]++;
	}
	for(auto it=m.begin();it!=m.end();it++)
	cout<<it->second<<" ";
	return 0;
}
