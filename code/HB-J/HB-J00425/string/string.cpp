#include<bits/stdc++.h>
using namespace std;
int n;
struct f
{
    long long g;
    char s;
}a[200005];
long long ans;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].g>>a[i].s;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].s==a[r].s)
        {
            if(a[l].g>a[r].g)
            {

                a[l].g=a[l].g-a[r].g;
                r--;
            }
            else if(a[l].g<a[r].g)
            {
                a[r].g=a[r].g-a[l].g;
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            if(a[l].g>a[r].g)
            {

                a[r].s=a[l].s;
                ans+=a[r].g;
                if(a[l].g>a[r].g)
                {

                    a[l].g=a[l].g-a[r].g;
                    r--;
                }
                else if(a[l].g<a[r].g)
                {
                    a[r].g=a[r].g-a[l].g;
                    l++;
                }
                else
                {
                    l++;
                    r--;
                }
            }
            else
            {
                a[l].s=a[r].s;
                ans+=a[l].g;
                if(a[l].g>a[r].g)
                {

                    a[l].g=a[l].g-a[r].g;
                    r--;
                }
                else if(a[l].g<a[r].g)
                {
                    a[r].g=a[r].g-a[l].g;
                    l++;
                }
                else
                {
                    l++;
                    r--;
                }
            }

        }
    }
    cout<<ans;
    return 0;
}
