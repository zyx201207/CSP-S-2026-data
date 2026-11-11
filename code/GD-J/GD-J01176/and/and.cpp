#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	cout<<(a[n-1]&a[n]);
	return 0;
}
