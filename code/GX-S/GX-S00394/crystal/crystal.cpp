#include<bits/stdc++.h>
using namespace std;
long long a[1001],n,m,s=0,d=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,n+a);
	for(;d<n;d++)
    {
        s+=a[d];
        if(a[d]*d-s>=m) break;
    }

    if(s==0) cout<<n;
    else if(d==0) cout<<'0';
    else cout<<d;
	return 0;
}
