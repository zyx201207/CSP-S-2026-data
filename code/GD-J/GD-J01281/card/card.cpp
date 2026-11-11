#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];
int ans[N];
int main()
{
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[i-1]) pos=i;
	}
	for(int i=pos;i<=n;i++)
	{
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
