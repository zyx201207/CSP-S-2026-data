#include<bits/stdc++.h>
using namespace std;
const int A=2e5+1;
int n,m,a[A];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[A-m];
		sort(a+A-m,a+A);
	}
	cout<<a[A-m];
	return 0;
}
