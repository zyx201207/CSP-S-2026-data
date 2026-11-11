#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    long long num;
    char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
    }
    long long ans=0;
    long long l=1,r=n,ln=a[1].num,rn=a[n].num;
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            if(ln<rn)
            {
                rn-=ln;
                l++;
                ln=a[l].num;
            }
            else if(ln>rn)
            {
                ln-=rn;
                r--;
                rn=a[r].num;
            }
            else
            {
                l++;r--;
                ln=a[l].num;rn=a[r].num;
            }
        }
        else
        {
            if(ln<rn)
            {
                rn-=ln;
                ans+=ln;
                l++;
                ln=a[l].num;
            }
            else if(ln>rn)
            {
                ln-=rn;
                ans+=rn;
                r--;
                rn=a[r].num;
            }
            else
            {
                ans+=ln;
                l++;r--;
                ln=a[l].num;rn=a[r].num;
            }
        }
    }
    cout<<ans;
    return 0;
}
