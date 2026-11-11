#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],c=pow(2,31)-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<m;i++)
		c=c&a[n-i-1];
	cout<<c;
	return 0;
}
