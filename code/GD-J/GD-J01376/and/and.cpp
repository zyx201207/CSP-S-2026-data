#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2000005];
int cmp(int a,int b)
{
	return a>b;
}
main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<a[m];
}
