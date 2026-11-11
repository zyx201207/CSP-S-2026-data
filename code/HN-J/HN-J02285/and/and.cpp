#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,n;
	cin>>n>>a;
	int zp[n];
	for(int i=0;i<n;i++)
	cin>>zp[i];
	sort(zp,zp+n);
	cout<<zp[a-1];
}
