#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
    long long L;
    char op;
}a[N];
long long pla[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].L>>a[i].op;
        pla[i]=pla[i-1]+a[i].L;
    }//p,q:将要选的
    long long p=1,q=n,x=0,y=0,ans=0;
    while(p<=q)
    {
        if(p==q)
        {
            if(x<=y)
                if(a[p].op!=a[q+1].op) ans=ans+y-x;
            else if(a[q].op!=a[p-1].op) ans=ans+x-y;
            break;
        }
        else if(x<=y)
        {
            long long nx=x+a[p].L;
            if(a[p].op!=a[q].op)
                if(nx>y) ans+=nx-y;
            x=nx;
            p++;
        }
        else
        {
            long long ny=y+a[q].L;
            if(a[p].op!=a[q].op)
                if(ny>x) ans+=ny-x;
            y=ny;
            q--;
        }
    }
    cout<<ans;
    return 0;
}
