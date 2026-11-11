#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b[1]=a[1];
	//cout<<b[1]<<endl;///////////////////////////////////////////////////////////////////
	//for(int i=1;i<=n;i++)
	//{
		//cout<<a[i]<<" ";////////////////////////////////////////////////////
	//}
	for(int i=2;i<=m;i++)
	{
		b[i]=b[i-1]&a[i];
		//cout<<b[i]<<endl;//////////////////////////////////////////////////////////////////////////////
	} 
	cout<<b[m];
	return 0;
}
