#include<bits/stdc++.h>
using namespace std;
const int mx=7E5+50;
long long a[mx],b[mx];
int n;
long long m;
bool pd(int l)
{
    for (int i=l;i<=n;i++)
    {
        long long x=a[i]*l-(b[l]-b[i-l]);
        //if (l==(314454+315430)/2)
        //cout<<x<<" "<<m<<endl;
        if (x<=m)
        return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    //for (int i=1;i<=n;i++)
    //    cout<<a[i]<<" "<<b[i]<<'\n';
    int l=1,r=n+1;
    while(l<r-1)
    {
        //cout<<l<<" "<<r<<endl;
        int an=(l+r)/2;
        bool B=pd(an);
        if (B)
        {
            l=an;
        }
        else
        {
            r=an;
        }
    }
    cout<<l;
    return 0;
}
/*
5 8 -3 -1 2 2 7
*/
