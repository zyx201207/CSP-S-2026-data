#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],b[2000005],ans;
int f(int x)
{
    int cnt=0;
    int r1=b[x],r2=b[x]-1,r3=b[x]-2;
    if(r2<=x) return cnt;
    if(r3<=x)
    {
        while(r1>r2)
        {
            r2=b[r2];
            if(r1==r2)
                break;
            cnt+=r2-r1;
            r1=b[r1];
            //cout << x << ' ' << r1 << '\n';
            if(r1==r2)
            {
                if(b[r2-1]==r2||b[r1]==0)
                    break;
                r2--;
            }
        }
        return cnt;
    }
    int fl=1;
    while(r1>r2)
    {
        if(fl)
        {
            r3=b[r3];
            if(r3<=r2) fl=0;
        }
        r2=b[r2];
        if(r1==r2)
            break;
        r1=b[r1];
        if(r3!=r2)cnt+=r2-r3;
        if(r1==r2)
        {
            if(b[r2-1]==r2||b[r1]==0)
                break;
            r2--;
            if(r3==r2&&fl&&b[r3-1]==r3) fl=0;
            r3--;
        }
        if(r2==r3)
        {
            if(b[r2-1]==r2||b[r1]==0)
                break;
            if(r3==r2&&fl&&b[r3-1]==r3) fl=0;
            r3--;
        }
    }
    return cnt;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _,__;
    cin >> _ >> __;
    while(__--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++)
        {
            int l=i,r=n;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(a[mid]>a[i]+m)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid;
                }
            }
            b[i]=l;
        }
        for(int i=1;i<=n-3;i++)
        {
            ans+=f(i);
        }
        cout << ans << '\n';
        ans=0;
    }
    return 0;
}
/*
5 3
-3 0 2 3 4
*/
