#include <bits/stdc++.h>
using namespace std;

struct nd
{
    long long x;
    char y;
    long long id;
}a[20000005];
long long tn,n;
long long ch()
{
    long long l=1,r=n;
    long long ans=0;
    long long t1=0,t2=0;
    while (l<=r)
    {
        if (a[l].x==a[r].x)
        {
            if (a[l].y!=a[r].y)
            {
                ans+=a[l].x;
            }
            a[l].x=0;
            a[r].x=0;
            l++;
            r--;
        }
        else if (a[l].x>a[r].x)
        {
            a[l].x-=a[r].x;
            if (a[l].y!=a[r].y)
            {
                ans+=a[r].x;
            }
            r--;
        }
        else
        {
            a[r].x-=a[l].x;
            if (a[l].y!=a[r].y)
            {
                ans+=a[l].x;
            }
            l++;
        }
    }
    return ans;
}
int main()
{
    fropen("string.in","r","stdin");
    fropen("string.out","w","stdout");
    cin >>n;
    string s="";
    for (long long i=1;i<=n;i++)
    {
        cin >>a[i].x>>a[i].y;
        tn+=a[i].x;
        a[i].id=a[i-1].id+a[i-1].x;
    }
    if (n==0)
    {
        cout <<0<<endl;
        return 0;
    }
    cout <<ch()<<endl;
    return 0;
}
