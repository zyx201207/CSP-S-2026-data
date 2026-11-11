#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) 
	{
		cout<<a[n];
		return 0;
	}
	ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
    return 0;
}

