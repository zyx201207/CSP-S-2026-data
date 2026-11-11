#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int a[n];
	int e[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		e[i]+=a[i]%2;
		a[i]=a[i]/2;
		cout<<e[i];
	}
	return 0;
}
