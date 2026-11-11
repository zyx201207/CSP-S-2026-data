#include<bits/stdc++.h>
using namespace std;
long long op[500010];
long long qzh[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,biggst=0,cnt=1;
    cin>>n>>m;
    long long g=m,z=0;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        if(op[i]<0) z=1;
    }
    for(int i=1;i<=n;i++)
    {
        qzh[i]=qzh[i-1]+op[i];
    }
    for(int i=1;i<=n;i++)
    {
        g=m;
        cnt=1;
        for(int j=i;j<=n;j++)
        {
            long long h=j*op[j]-qzh[j];
            if(h<=g)
            {
                g-=h;
                cnt++;
            }
            else
            {
                break;

            }
        }
        if(cnt>biggst)
        {
            biggst=cnt;
        }
    }
    if(z==1) biggst++;
    cout<<biggst;
    return 0;
}
