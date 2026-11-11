#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,cha[500005],t,maxx=-999999999999,sum,fflag,flag;
signed main(void)
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<n;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
    {
        if(a[i]+1!=a[i+1])
        {
            fflag=1;
            break;
        }
    }
    if(fflag==0)
    {
        int ant=1,summ=1;
        while(m>=ant)
        {
            m=m-ant;
            summ++;
            if(m>=ant)
            {
                m=m-ant;
                summ++;
                ant++;
            }
        }
        cout<<min(summ,n);
        return 0;
    }
    for(int i=1;i<n;i++)cha[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++)
    {
        sum-=(cha[i-1]*(i-1));
        while(sum+cha[t+1]*(t+1)<=m && t+1<n)sum+=cha[++t]*t;
        maxx=max(maxx,t-i+2);
    }
    cout<<maxx;
    return 0;
}
