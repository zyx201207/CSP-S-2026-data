#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000];
int sum=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=n;i>n-m;i--){
		sum=a[i]&a[i-1];
	}
	cout<<sum;
	return 0;
}
