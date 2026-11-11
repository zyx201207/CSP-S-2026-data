#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],st[200005],cnt;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    st[1]=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        st[i+1]=st[i]+a[i];
    }
    long long mid=(st[n+1]-1)-(st[n+1]-1)/2,t1=mid+1,t2;
    for(int i=1;i<=n;i++)
    {
        if(t1>=st[i]&&t1<st[i+1])
        {
            t2=i;
            break;
        }
    }
    for(int i=1;i<=n&&st[i]<=mid;i++)
    {
        if(st[i+1]-1<=(st[n+1]-1)/2)
        {
            long long r=t1;
            t1+=a[i];
            while(1)
            {
                if(t2>n) break;
                if(st[t2+1]<=t1)
                {
                    if(c[t2]!=c[i]) cnt+=(st[t2+1]-r);
                    r=st[t2+1];
                    t2++;
                }
                else
                {
                    if(c[t2]!=c[i]) cnt+=(t1-r);
                    break;
                }
            }
        }
        else
        {
            long long r=t1;
            while(1)
            {
                if(t2>n) break;
                if(c[t2]!=c[i]) cnt+=(st[t2+1]-r);
                r=st[t2+1];
                t2++;
            }
            break;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
