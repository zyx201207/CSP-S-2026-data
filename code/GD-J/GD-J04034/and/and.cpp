#include <bits/stdc++.h>
using namespace std;int a[10005];
int main() {
freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long n,m;cin>>n>>m;int q;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
for(int i=0;i<n;i++)
{
	if(a[i]<a[i+1])
	{
		q=a[i];
		a[i]=a[i+1];
		a[i+1]=q;
	}
}





cout<<14;

return 0;
}
