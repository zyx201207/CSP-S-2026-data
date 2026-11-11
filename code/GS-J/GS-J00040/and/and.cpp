#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxx=-2147483046;
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		int ans=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			ans&=a[j];
		}
		maxx=max(maxx,ans);
	}
	cout <<maxx;
	return 0;
}
