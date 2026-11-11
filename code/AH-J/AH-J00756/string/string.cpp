#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,t,h=1,ant,cnt;
struct node
{
    int m;
    char s;
}a[200005];
signed main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].m>>a[i].s;
    t=n;
    ant=a[1].m;
    cnt=a[n].m;
    while(h<t)
    {
        if(a[h].s!=a[t].s)
        {
            if(ant>=cnt)
            {
                sum+=cnt;
                ant-=cnt;
                t--;
                cnt=a[t].m;
            }
            else
            {
                sum+=ant;
                cnt-=ant;
                h++;
                ant=a[h].m;
            }
        }
        else
        {
            if(ant>=cnt)
            {
                ant-=cnt;
                t--;
                cnt=a[t].m;
            }
            else
            {
                cnt-=ant;
                h++;
                ant=a[h].m;
            }
        }
    }
    cout<<sum;
    return 0;
}
