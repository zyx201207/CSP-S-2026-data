#include<iostream>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int MAXN=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]&a[j]>MAXN)
				MAXN=a[i]&a[j];
		}
	}
	cout<<MAXN;
	return 0;
}
