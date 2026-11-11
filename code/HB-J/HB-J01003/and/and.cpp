#include<bits/stdc++.h>
using namespace std;
struct eee
{
    int b=0,c=0,d=0;
}a[200005];
bool cmp(eee a,eee b)
{
    return a.c<b.c;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0,m=0,ma=0,fj=2;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].b;
        a[i].d=a[i].b;
        while(a[i].d)
        {
            a[i].c+=(a[i].d%2);
            a[i].d/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    ma=a[n].b&a[n-1].b;
    for(int i=m-2;i>=1;i--)
    {
        ma&=a[n-fj].b;
        fj++;
    }
    cout<<ma;
    return 0;
}
