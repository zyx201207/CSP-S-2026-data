#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m,o;
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	o=a[n-1];
	for (int i=1;i<m;i++)
		o=o&a[n-1-i];
	cout<<o;
	return 0;
}
