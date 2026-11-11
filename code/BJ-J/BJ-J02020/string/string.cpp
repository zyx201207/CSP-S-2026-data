#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node
{
    ll v;
    char c;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    ll ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v>>a[i].c;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            if(a[l].v>a[r].v)
            {
                a[l].v-=a[r].v;
                r--;
            }
            else if(a[l].v==a[r].v)
            {
                r--;
                l++;
            }
            else
            {
                a[r].v-=a[l].v;
                l++;
            }
        }
        else
        {
            if(a[l].v>a[r].v)
            {
                a[r].c=a[l].c;
                ans+=a[r].v;
                a[l].v-=a[r].v;
                r--;
            }
            else
            {
                a[l].c=a[r].c;
                ans+=a[l].v;
                a[r].v-=a[l].v;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}

