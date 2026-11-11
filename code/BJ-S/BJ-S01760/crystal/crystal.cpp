#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long a[N];
int cnt;
void merge(int x)
{
	for(int i=1;i<=x;i++)
	{
		if(a[x]!=a[x+1])
		{
			a[x]+=a[x+1];
			cnt++;
		}
	}
	return;
}
int main()
{
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		merge(a[i]);
	}
	cout<<cnt;
	return 0;
}
