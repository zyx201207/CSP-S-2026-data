#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node
{
    int v;
    char ch;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v>>a[i].ch;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].v>a[r].v)
        {
            while(a[l].v>a[r].v)
            {
                if(a[l].ch!=a[r].ch)
                {
                    ans+=a[r].v;
                }
                a[l].v-=a[r].v;
                r--;
            }
            if(a[l].ch!=a[r].ch)
            {
                ans+=a[l].v;
            }
            a[r].v-=a[l].v;
            l++;
        }
        else if(a[l].v<a[r].v)
        {
            while(a[r].v>a[l].v)
            {
                if(a[l].ch!=a[r].ch)
                {
                    ans+=a[l].v;
                }
                a[r].v-=a[l].v;
                l++;
            }
            if(a[l].ch!=a[r].ch)
            {
                ans+=a[r].v;
            }
            a[l].v-=a[r].v;
            r--;
        }
        else
        {
            if(a[l].ch!=a[r].ch)
            {
                ans+=a[l].v;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}