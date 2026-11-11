#include<bits/stdc++.h>
#define int long long
using namespace std;

struct hw
{
    int b;
    char c;
}a[200010];

int nn, L, lyy;
int n, m, l, r;
char x, y;

signed main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&nn);
    for(int i=1; i<=nn; i++)
    {
        scanf("%lld",&a[i].b);
        cin>>a[i].c;
        L+=a[i].b;
    }
    n=a[1].b;
    m=a[nn].b;
    x=a[1].c;
    y=a[nn].c;
    l=1, r=nn;
    while(l<r)
    {
        //cout<<x<<" "<<y<<endl;
        if(x!=y)
        {
            if(n>m)
            {
                lyy+=m;
                n=n-m;
                r--;
                m=a[r].b;
                y=a[r].c;
            }
            else if(n<m)
            {
                lyy+=n;
                m=m-n;
                l++;
                n=a[l].b;
                x=a[l].c;
            }
            else if(n==m)
            {
                lyy+=n;
                l++,r--;
                m=a[r].b;
                y=a[r].c;
                n=a[l].b;
                x=a[l].c;
            }
        }
        else{
            if(n>m)
            {
                n=n-m;
                r--;
                m=a[r].b;
                y=a[r].c;
            }
            else if(n<m)
            {
                m=m-n;
                l++;
                n=a[l].b;
                x=a[l].c;
            }
            else if(n==m)
            {
                l++,r--;
                m=a[r].b;
                y=a[r].c;
                n=a[l].b;
                x=a[l].c;
            }
        }
    }
    printf("%lld",lyy);
    return 0;
}
