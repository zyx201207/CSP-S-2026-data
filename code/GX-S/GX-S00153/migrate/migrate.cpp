#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,a[N],d,cnt,minn;
void dfs(int l,int r,int times)
{
    //cout<<l<<' '<<r<<" "<<times<<"\n";
    if(l==r)
    {
        if(times==minn)
            cnt+=1;
        return;
    }
    for(int i=l+1;i<=r;++i)
    {
        if(a[i]-a[l]<=d)
            dfs(i,r,times+1);
        else
            break;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;++i)   cin>>a[i];
        int ans=0;
        if(d>=a[n]-a[1]||n<=3)
        {
            cout<<0<<"\n";
            continue;
        }
        if(c<=10)
        {

            for(int i=1;i<=n-3;++i)
            {
                for(int j=i+3;j<=n;++j)
                {
                    int x=i,k;
                    minn=0;
                    bool f=0;
                    for(k=a[i];k<=a[j];)
                    {
                        k+=d;
                        ++x;
                        if(a[x]>k)
                        {
                            f=1;
                            break;
                        }
                        while(a[x+1]<=k&&x<j)   ++x;
                        k=a[x];
                        //++x;
                        ++minn;
                        //cout<<x<<"@@@\n";
                        if(x>=j)    break;
                    }
                    //cout<<minn<<"!\n";
                    if(f)   break;
                    cnt=0;
                    dfs(i,j,0);
                    if(cnt==2)  ++ans;
                }
            }
            cout<<ans<<"\n";
        }
        else if(c==13||c==14)
        {
            int posr=0,posl=0;
            for(int i=1;i<=n;++i)
            {
                if(a[i]-a[1]>d)
                {
                    posr=i-1;
                    break;
                }

            }
            for(int i=n;i>=1;--i)
            {
                if(a[n]-a[i]>d)
                {
                    posl=i+1;
                    break;
                }
            }
            if(posr-posl>1)
            {
                cout<<0<<"\n";
            }
            else if(posr-posl==1)
            {
                ans=1;
                for(int i=2;i<posl;++i)
                {
                    if(a[i]+d>=a[posr+1])
                    {
                        ans+=posl-i;
                        break;
                    }
                }
            }
            else
            {
                int i;
                for(i=2;i<posl;++i)
                {
                    if(a[i]+d>=a[posr+1])
                    {
                        ans+=posl-i;
                        break;
                    }
                }
                for(int j=i+1;j<posl;++j)
                {
                    if(a[j]+d>=a[posr+2])
                    {
                        ans-=posl-j;
                        break;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        else    cout<<0<<"\n";
    }
    return 0;
}
