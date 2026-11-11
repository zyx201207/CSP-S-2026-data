#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5;
ll n,m;
ll a[N],b[N],h[N];
ll start=1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    while(start<=n)
    {
        memset(b,0,sizeof(b) );
        int curpos=1;
        for(ll i=start;i<=n;++i)
        {
            bool flag=1;
            int pos=0;
            //先判断数组内是否有相同的数字
            for(ll j=1;j<=n;++j)
            {
                if(b[j]==a[i])
                {
                    pos=j;
                    flag=0;
                    //清空后面所有的数
                    for(ll k=j;k<=n;++k)
                    {
                        b[k]=0;
                    }
                    break;
                }
            }
            if(flag)
            {
                b[curpos]=a[i];
                curpos++;
            }
            else
            {
                b[pos]=a[i];
            }
        }
        //哈希统计数
        for(ll x=1;x<=m;++x)
        {
            h[b[x]]++;
        }
        start++;
    }
    for(ll i=1;i<=m;++i)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}
