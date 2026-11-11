#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
