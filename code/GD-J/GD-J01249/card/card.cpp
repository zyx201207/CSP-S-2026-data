#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,m,a[N],c[N],d[N],v[N],ans[N];
bool o;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]=i;	
		d[a[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}

