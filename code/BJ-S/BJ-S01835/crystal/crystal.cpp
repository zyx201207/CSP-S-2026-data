#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int c;
int a[500005];
int sum;
int x,y,w1,w2;
bool cmp(int u, int v)
{
    return u<v;
}
bool cmp1(int u, int v)
{
    if(u<=a[y]) w1=a[y]-u;
    else w1=(u-a[y])*sum;
    if(v<=a[y]) w2=a[y]-v;
    else w2=(v-a[y])*sum;
    sum++;
    return w1<w2;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int x,y;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    y=2,x=1;
    sum=2;
    for(int i=2; i<=n; i++)
    {
        if(a[i]-a[i-1]<a[y]-a[x])
        {
            y=i,x=i-1;
        }
    }
    int cnt=0;
    sort(a+1,a+1+n,cmp1);
    if(m-(a[y]-a[x])<0) {cout<<1; return 0;}
    for(int i=1; i<=n; i++)
    {
        if(a[i]<a[y])
        {
            if(m-(a[y]-a[i])>=0)
            {
                m-=a[y]-a[i];
                cout<<m;
                cnt++;
            }
            else{
                break;
            }
        }
        else{
            if(m-(a[i]-a[y])*cnt>=0){
                m-=(a[i]-a[y])*cnt;
                y=i;
                cout<<m;
                cnt++;
            }
            else break;
        }
    }
    cout<<cnt;
    return 0;
}
