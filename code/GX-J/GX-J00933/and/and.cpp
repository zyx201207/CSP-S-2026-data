#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans,bj[200001];
void f(long long s,long long w)
{
    if(w==m)
    {
        ans=max(ans,s);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(bj[i]==0)
        {
            bj[i]=1;
            f(s^a[i],w+1);
            bj[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        bj[i]=1;
        f(a[i],1);
        bj[i]=0;

    }
    cout<<ans;
    return 0;
}
