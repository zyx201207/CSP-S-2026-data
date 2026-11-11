#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
vector<int>f[300010];
int a[500010],s[300010];
void hs(int q)
{
	for(auto i:f[q])
	{
		hs(i);
		s[q]+=s[i];
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(s[a[i]]==0)
			f[a[i+1]].push_back(a[i]);
		s[a[i]]++;		
	}
	hs(a[n]);
	for(int i=1;i<=m;i++)
		cout<<s[i]<<' ';
	return 0;
}

