#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[111111];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxx=-999;
	sort(a+1,a+n+1);
	cout<<a[n-1];
	return 0;
}
