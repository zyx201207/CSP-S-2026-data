#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20005];
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	return 0; 
}
