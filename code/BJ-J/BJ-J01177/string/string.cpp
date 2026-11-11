#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans = 0;
    int n,a[200005];
    char c[200005];
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d %c",&a[i],&c[i]);
    }
    int j = n;
    bool fi = true,fj = true;
    for(int i = 1;i <= n;i++)
    {
        fi = true;
        fj = true;
        int mi = min(a[i],a[j]);
        if(c[i] != c[j])
        {
            ans += mi;
            a[i] -= mi;
            a[j] -= mi;
            if(a[i] != 0)
            {
                fi = false;
            }
            if(a[j] != 0)
            {
                fj = false;
            }
        }
        else
        {
            a[i] -= mi;
            a[j] -= mi;
            if(a[i] != 0)
            {
                fi = false;
            }
            if(a[j] != 0)
            {
                fj = false;
            }
        }
        if(i == j)
            break;
        if(i + 1 == j)
            break;
        if(!fi)
        {
            i--;
        }
        if(!fj)
        {
            j++;
        }
        j--;
    }
    printf("%lld",ans);
    return 0;
}
