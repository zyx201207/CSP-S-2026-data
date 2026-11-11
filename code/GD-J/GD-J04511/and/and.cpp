#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=-1,cnt=0x7f7f7f7f,a[200005];
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m;i--)
	{
		cnt&=a[i];
	}
	cout<<cnt;
    return 0;
}
