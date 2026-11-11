#include<bits/stdc++.h>
using namespace std;
long long n, len=0;
struct node
{
    long long x;
    char c;
}a[200005], b[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
    long long cnt=0;
    for(long long i=1;i<=n;i++)
    {
        if(a[i].c==b[cnt].c)
        {
            b[cnt].x+=a[i].x;
        }
        else
        {
            b[++cnt]=a[i];
        }
    }
    for(long long i=1;i<=cnt;i++) len+=b[i].x;
    long long l=0, r=len+1, L=1, R=cnt, ans=0;
    while(true)
    {
        long long X=min(b[L].x, b[R].x);
        if(b[L].c!=b[R].c)
        {
            ans+=X;
            if(l+X>r-X) ans-=(l+X)-(r-X);
        }
        l+=X;
        r-=X;
        b[L].x-=X;
        b[R].x-=X;
        if(b[L].x==0) L++;
        if(b[R].x==0) R--;
        if(r-l<=1) break;
    }
    cout<<ans;
    return 0;
}