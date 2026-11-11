#include<bits/stdc++.h>
using namespace std;
int n,nn,luck[200005],rpi,cnt;
struct csp
{
    int a,b
}rp[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>rp[i].a>>rp[i].b;
        nn+=rp[i].b;
        for(int j=1;i<=rp[i].b;j++)
        {
            luck[j+rpi]=rp[i].a;
        }
        rpi+=rp[i].b;
    }
    int m=nn/2;
    if(nn&2==1)
    {
        m+=1;
    }
    for(int i=1;i<=nn/2;i++)
    {
        if(a[i+m]!=a[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
