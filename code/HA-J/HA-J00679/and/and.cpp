#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int n,m,a[99999999];
int main() {
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
}
