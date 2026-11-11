#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=0,c=1;
void my_main(int ts,int i,int ns)
{
	if(ns==0)
	{
		cout<<maxn<<" "<<c<<'\n';
		if(ts>maxn) maxn=ts;
	}
	for(int j=1;j<i;j++)
	{c++;
		my_main(ts&a[j],j,ns-1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		my_main(a[i],i,m-1);
	}
	cout<<maxn;
}
