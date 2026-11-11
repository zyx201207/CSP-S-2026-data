#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],aa[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for (int y=0;y<m;y++){
		aa[y]=a[(n-m)/2+y];
	}
	cout<<aa[m-1];
}
