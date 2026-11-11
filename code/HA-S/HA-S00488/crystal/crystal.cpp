#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,a[100003],ans=-1;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            long long sum=0;
            for(int k=i;k<=j;k++)
                sum+=a[j]-a[k];
            if(sum<=m && ans<j-i+1)
                ans=j-i+1;
        }
    }
    cout << ans;
    return 0;
}
