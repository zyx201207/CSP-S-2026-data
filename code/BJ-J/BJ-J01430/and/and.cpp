#include<bits/stdc++.h>
using namespace std;
long long n, m, a[2000005], b[305], M=30;
bool ans[305], c[2000005][305], F=false;
void abc(long long x)
{
    long long i=0, y=x;
    while(x)
    {
        b[i]+=x&1;
        c[y][i++]=x&1;
        x/=2;
    }
}
void def()
{
    memset(b, 0, sizeof(b));
    for(long long i=1;i<=n;i++)
    {
        if(a[i]) abc(a[i]);
    }
    long long x=-1;
    for(long long i=M;i>=0;i--)
    {
        if(b[i]>=m)
        {
            x=i;
            break;
        }
    }
    if(x==-1)
    {
        F=true;
        return;
    }
    M=x-1;
    ans[x]=true;
    for(long long i=1;i<=n;i++)
    {
        if(!c[a[i]][x]) a[i]=0;
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=30;i>=0;i--) if(!F) def();
    bool flag=false;
    long long X=1, ANS=0;
    for(long long i=0;i<=30;i++)
    {
        if(ans[i]) ANS+=X;
        X*=2;
    }
    cout<<ANS;
    return 0;
}