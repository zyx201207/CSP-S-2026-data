#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct and_a
{
    int x,num;
}a[200005];
bool cmp(and_a y,and_a z)
{
    if(y.num!=z.num) return y.num>z.num;
    return y.x>z.x;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        int ai=a[i].x;
        while(ai)
        {
            if(ai%2==1) a[i].num++;
            ai/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1].x;
    for(int i=2;i<=m;i++)
        ans&=a[i].x;
    cout<<ans;
    return 0;
}