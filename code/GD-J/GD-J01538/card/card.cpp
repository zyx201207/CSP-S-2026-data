#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],l[N];
int s[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=1;i<=n;++i)
	{
		++s[a[i]];
		if(l[a[i-1]]==i-1)
		{
			s[a[i]]+=s[a[i-1]];
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<s[i]<<" ";
	}
}
