#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	  cin>>a[i];
	for(i=0;i<n;i++)
	  j=a[i]&j;
	cout<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
