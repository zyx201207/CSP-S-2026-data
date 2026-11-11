#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=3e6+5;
int a[N],n,cnt=0,nm,ANS,m;
struct A
{
    int v;
    bool operator <(const A&other)
    const
    {
        return v>other.v;
    }
}TT;
priority_queue <A>q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        nm+=(a[i]-a[i-1])*cnt;
        TT.v=a[i];
        cnt++;
        q.push(TT);
        while(nm>m)
        {
            TT=q.top();
            q.pop();
            nm-=(a[i]-TT.v);
            cnt--;
        }
        ANS=max(ANS,cnt);
    }
    printf("%lld ",ANS);
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14
./crystal
*/