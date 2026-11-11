#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],maxi;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		while(a[i]>0)
//		{
//			b[i]=b[i]*10+a[i]%2;
//			a[i]/=2;
//		}
//	}
	sort(a+1,a+1+n,cmp);
	sort(a+1,a+1+m);
	cout<<a[1]<<'\n';
	return 0;
}
