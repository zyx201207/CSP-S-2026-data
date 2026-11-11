#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
long long m,n,a[N],k;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	k=max(a[i],k);
}
if(m==1)
{
	cout<<k;
}
else
{
	sort(a+1,a+1+n);
	cout<<a[n-m];
}
return 0;
}
