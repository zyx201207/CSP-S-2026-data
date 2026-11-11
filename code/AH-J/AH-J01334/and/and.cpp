#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){cout<<a[n];return 0;}
	int t=a[n];
	for(int i=n-1;i>=n-m+1;i--)t=t&a[i];
	cout<<t;
	return 0;
}
