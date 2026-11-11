#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    if(n%2==1)
    {
        int l=(n/2),r=(n/2)+2,t=a[n/2+1],cnt=1;
        while(m>0)
        {
            if(l<=0||r>n)
                break;
            if(t-a[l]<a[r]-t&&m>=t-a[l])
                m-=(t-a[l]),l--,cnt++;
            else
                if(m>=a[r]-t)
                    m-=(a[r]-t),r++,cnt++;
        }
        cout << cnt;
    }
    else
    {
        int l=(n/2)-1,r=(n/2)+1,t=a[n/2],cnt=1;
        while(m>0)
        {
            if(l<=0||r>n)
                break;
            if(t-a[l]<a[r]-t&&m>=t-a[l])
                m-=(t-a[l]),l--,cnt++;
            else
                if(m>=a[r]-t)
                    m-=(a[r]-t),r++,cnt++;
        }
        l=(n/2),r=(n/2)+2,t=a[n/2+1];
        int tnc=1;
        while(m>0)
        {
            if(l<=0||r>n)
                break;
            if(t-a[l]<a[r]-t&&m>=t-a[l])
                m-=(t-a[l]),l--,tnc++;
            else
                if(m>=a[r]-t)
                    m-=(a[r]-t),r++,tnc++;
        }
        cout << max(cnt,tnc);
    }
    return 0;
}
