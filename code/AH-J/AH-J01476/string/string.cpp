#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node
{
    int a;
    char b;
}z[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>z[i].a>>z[i].b;
    for(int i=1;i<=n/2+1;i++)
    {
        if(z[i].b==z[n-i+1].b&&i<=n-i+1)
        {
            if(z[i].a!=z[n-i+1].a&&i+1!=n-i+1&&z[i+1].b!=z[i].b&&z[n-i].b!=z[n-i+1].b)
            {
                int cnt=abs(z[i].a-z[n-i+1].a);
                sum+=cnt;
                if(z[i].a>z[n-i+1].a)z[n-i].a-=cnt;
                else z[i].a-=cnt;
            }
        }
        else if(z[i].b!=z[n-i+1].b&&i<=n-i+1)
        {
            int cnt=min(z[i].a,z[n-i+1].a);
            sum+=cnt;
            if(z[i].a>z[n-i+1].a)z[n-i].a-=cnt+z[n-i+1].a;
            else z[i].a-=cnt+z[n-i+1].a;
        }
    }
    cout<<sum;
    return 0;
}
