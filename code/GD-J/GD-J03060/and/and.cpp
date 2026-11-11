#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>a[i];
	int m1=a[n-m-1],mx=0;
	sort(a,a+n);
	for(int i=n-1;i>=n-m+1;i--){
		m1=m1&a[i];
	}
	mx=max(mx,m1);
	cout<<mx;
	return 0;
}
