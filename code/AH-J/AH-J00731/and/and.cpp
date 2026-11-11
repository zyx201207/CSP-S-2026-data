#include <bits/stdc++.h>
using namespace std;
long long n,m,a[11111111];
bool f(const int &a,const int &b)
{
	return a>b;
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,f);
	cout<<a[m];
	return 0;
}
