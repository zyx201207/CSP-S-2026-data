#include<iostream>
using namespace std;
int n,a[10000],c;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n];
    return 0;
}
