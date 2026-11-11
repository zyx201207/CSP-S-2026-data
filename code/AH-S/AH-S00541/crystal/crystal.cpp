#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],b[N],cnt;
inline int read()
{
    int x=0,f=1;char ch=getchar_unlocked();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar_unlocked();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar_unlocked();}
    return x*f;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+1+n);
    if(a[1]==a[n+1]){cout<<n<<endl;return 0;}
    else if(n>=5000)
    {
        int k=m,t=0,ans=0;
        for(int i=1;i<=n;i++)
            b[i]=a[n+1]-a[i];
        while(k)
        {
            if(k-b[++t]>=0)
            {
                k-=b[t];
                ans++;
            }
            else break;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int k=m;
        for(int j=1;j<=n;j++)
            if(a[j]-a[i]<=0)b[j]=a[i]-a[j];
            else b[j]=1e10;
        sort(b+1,b+1+n);
        int t=0,ans=0;
        while(k)
        {
            if(k-b[++t]>=0)
            {
                k-=b[t];
                ans++;
            }
            else break;
        }
        cnt=max(ans,cnt);
    }
    cout<<cnt<<endl;
    return 0;
}
//75?!
