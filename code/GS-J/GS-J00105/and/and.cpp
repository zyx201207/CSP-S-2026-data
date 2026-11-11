#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n-1]<<endl;
	return 0;
}
