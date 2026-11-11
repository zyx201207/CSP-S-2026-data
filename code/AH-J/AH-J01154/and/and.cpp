#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		ans=max(ans,a[i]);
	}
    cout<<ans;
    return 0;
}
