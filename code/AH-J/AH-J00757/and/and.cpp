#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[3355306],v[3355306];
int ans;
void zzz(int x,int k,int id)
{
    if(x==m)
    {
        ans=max(ans,k);
        //cout<<ans<<"! "<<k<<"?\n";
        return;
    }
    for(int i=id;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            int h=k;
            k&=a[i];
            zzz(x+1,k,id);
            k=h;
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)v[i]=1,zzz(1,a[i],i);//cout<<ans<<"!!!\n";
    cout<<ans;
    return 0;
}//No Time  yellow
//50 point?
