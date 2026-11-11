#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    f[1]=a[1];
    for(long long i=2;i<=n;i++)
    {
    	for(long long j=min(i,m);j>=2;j--)
    	{
    		f[j]=max(f[j],(f[j-1]&a[i]));//cout<<j<<" "<<f[j]<<endl;
		}
		f[1]=max(a[i],f[1]);
	}
	cout<<f[m];
	return 0;
}
