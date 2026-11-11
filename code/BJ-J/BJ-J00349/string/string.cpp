#include <bits/stdc++.h>
using namespace std;
struct rev
{
    long long num,pos;
    char c;
}a[1001000];
long long dis[200100];
long long sum,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        long long x;
        char c1;
        cin>>x>>c1;
        sum+=x;
        a[i].num=x,a[i].c=c1;
        if (i==1)
        {
            a[i].pos=x;
            dis[i]=x;
        }
        else
        {
            dis[i]=dis[i-1]+x;
            a[i].pos=a[i-1].pos+x;
        }
    }

    for (int i=1;i<=n/2;i++)
    {
        int pos=upper_bound(dis+1,dis+n+1,sum-dis[i])-dis;
        if (a[pos].c!=a[i].c) ans+=a[i].num;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
