#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m-1;i++)
	{
		cout<<(a[n-i]&a[n-i+1]);
	}
	return 0;
} 
