#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	unique(a,a+n+1);
	cout<<a[m]<<endl;
	return 0;
}