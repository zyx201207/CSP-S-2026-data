#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	sum=a[n-1];
	for(int i=n-2;i>=0;i--) sum&=a[i];
	cout<<sum;
	return 0;
}
