#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n-1);
	cout<<a[n-m];
	return 0;
}
