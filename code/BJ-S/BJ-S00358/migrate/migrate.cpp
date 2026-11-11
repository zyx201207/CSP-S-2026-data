#include <bits/stdc++.h>
using namespace std;
int c;
int t;
int n;
int d;
int D;
int mid;
int ans;
int a[2000010];
bool A=1;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        D=a[2]-a[1];
        for (int i=1;i<=n-1;i++)
        {
            if (a[i+1]-a[i]!=D)
            {
                A=0;
            }
        }
        if (A)
        {
            for (int i=1;i<=n;i++)
            {
                mid=i>>1;
                if (a[mid]-a[1]<d&&a[i]-a[1]>d&&a[i]-a[mid]<=d)
                {
                    ans++;
                }
            }
            cout<<ans;
            continue;
        }
        cout<<0;
    }
    return 0;
}
