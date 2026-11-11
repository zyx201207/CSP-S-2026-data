#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sort(a[i],a[i-1]);
		cout<<a[i]*a[i-1];
	}
	return 0;
}
