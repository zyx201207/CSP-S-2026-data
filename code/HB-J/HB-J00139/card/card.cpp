#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int d[N],a[N],b[N];
int n,m;
void find(int x)
{
	if(x>n) return;
	if(a[d[x]]==0)
	{
		a[d[x]]=x;
		b[d[x]]++;
		find(x+1);
	}else
	{
		b[d[x]]++;
		find(a[d[x]]+1);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	for(int i=n;i>=1;i--)
	{
		find(i);
	}
	for(int i=0;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
