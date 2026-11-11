#include <bits/stdc++.h>

using namespace std;
string b[200005];
int k;
bool cmp(string x,string y)
{
    return x[31-k]>y[31-k];
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    unsigned maxx=1;
    for(int i=1;i<=n;i++)
    {
        unsigned t;
        scanf("%u",&t);
        maxx=max(maxx,t);
        for(int j=0;j<=31;j++)
        {
            b[i]=char((t&1)+'0')+b[i];
            t>>=1;
        }
    }
    unsigned s=1;
    while(maxx>=s)s<<=1,k++;
    k--;

    unsigned ans=0,po=pow(2,k);
    for(;k>=0;k--)
    {
        sort(b+1,b+1+n,cmp);
        int h=0;
        while(h+1<=n&&b[h+1][31-k]=='1')h++;
        if(h>=m)ans+=po,n=h;
        po>>=1;
    }
    printf("%u",ans);
}
