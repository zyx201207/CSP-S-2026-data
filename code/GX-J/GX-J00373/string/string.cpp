#include <bits/stdc++.h>
using namespace std;
char c[200005],d[200005],cl,cr;
int n,a[200005],b[200005],i,j;
long long cnt,ans,mid,l,r,cnt1,cnt2,x,y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(i = 1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        b[n-i+1]=a[i];
        d[n-i+1]=c[i];
        cnt+=a[i];
    }
    mid=cnt/2;
    j=0;
    for(i =1;i<=n;)
    {
        while(l<=r)
        {
            l+=a[i];
            cl=c[i];
            if(cl!=cr && cr!=0)
            {
                ans+=a[i]-cnt2;
                cnt2-=a[i];
            }
            i++;
        }

        while(r<=l)
        {
            j++;
            r+=b[j];
            cr=d[j];
            if(r<=l)
            {
                if(cl!=cr)
                {
                    ans+=b[j];
                }
            }
            else
            {
                cnt2=r-l;
                if(cl!=cr)
                {
                    ans+=b[j]-cnt2;
                }

            }
        }

    }
    cout << ans/2;
    return 0;
}
