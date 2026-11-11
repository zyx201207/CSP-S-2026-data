#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
bool cmp(int x,int y)
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
	int maxans=-1;
	for(int i=1;i<=n;i++)
	{
		int ans0=a[i];
		for(int j=1;j<m;j++)
		{
			ans0&=a[i+j];
		}
		if(maxans<=ans0)
		{
			maxans=ans0;
		}
		else
		{
			break;
		}
	}
	cout<<maxans<<endl;
	return 0;
 } 
