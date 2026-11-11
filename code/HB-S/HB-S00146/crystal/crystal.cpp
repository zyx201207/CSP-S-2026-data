#include <bits/stdc++.h>
using namespace std;
long long n,m,mx,cnt,ans,ans1,k,m1;
long long a[500010],b[500010],c[500010],d[500010],e[500010];
//a->sort_origin,c->cnt,d->num,e->delta
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    m1=m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    b[1]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]) b[i]=b[i-1];
        else
        {
            b[i]=b[i-1]+1;
            d[b[i]]=a[i];
        }
        c[b[i]]++;
    }
    cnt=b[n];
    for(int i=2;i<=cnt;i++)
    {
        e[i]=d[i]-d[i-1];
    }
    for(int i=1;i<=cnt;i++)
    {
        ans1=c[i],m=m1,k=0;
        for(int j=i;j>=2;j--)
        {
            k+=e[j];
            //cout<<k<<" ";
            //if(i==5) cout<<m<<" "<<k<<" "<<ans1<<endl;
            if(m>k*c[j-1])
            {
                m-=k*c[j-1];
                ans1+=c[j-1];
                //if(i==5) cout<<m<<" ";
            }
            else {
                ans1+=m/k;
                break;
            }
        }
        //cout<<endl;
        //cout<<ans<<" "<<ans1<<endl;
        ans=max(ans,ans1);
    }
    cout<<ans;
    /*
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt;i++) cout<<c[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt;i++) cout<<d[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt;i++) cout<<e[i]<<" ";
    cout<<endl;
    */
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
/*
5 5
1 2 4 8 9
*/
