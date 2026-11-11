#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+210;
map<int,int>s;
int t[N];
int a[N];
int q[N];
int ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=a[i-1])
		{
			s[a[i]]=max(s[a[i]],i);
		}
	}
	for(int i=1;i<=m;i++)cout<<s[a[i]]<<" ";
	return 0;
}

