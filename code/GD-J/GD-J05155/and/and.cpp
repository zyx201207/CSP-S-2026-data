#include<iostream>
using namespace std;
int main()
{
	int n,m,a[10000010]={};
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]); 
			} 
		}
	}
	cout<<a[m];
	return 0;
}
