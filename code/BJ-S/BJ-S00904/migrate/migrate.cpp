#include<bits/stdc++.h>
using namespace std;
int cnt[10][10][10];
long long c,t,n,d,ans;
long long x[(int)2e6+10];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c;
    if(1<=c and c<=2)
    {
        cin>>t;
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    for(int k=1;k<=n;k++)
                    {
                        cnt[i][j][k]=0;
                    }
                }
            }
            for(int k=3;k<(1<<n);k++)
            {
                int fs=0,ls=0,lst=0,ln=0;
                for(int i=1;i<=n;i++)
                {
                    if(k&(1<<(i-1)))
                    {
                        ln++;
                        if(!fs) fs=i;
                        else ls=i;
                        if(lst!=0 and x[i]-x[lst]>d) ln=114514;
                        lst=i;
                    }
                }
                if(fs!=ls and ls!=0 and ln<114514) cnt[fs][ls][ln-1]++;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(cnt[i][j][k]!=0)
                        {
                            if(cnt[i][j][k]==2) ans++;
                            else break;
                        }
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    else if(c==0 or c==11 or c==12)
    {
        cin>>t;
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1)
            {cout<<0<<"\n";continue;
            }
            long long c;
            c=x[2]-x[1];
            c=abs(c);
            int l=n-1;
            if(c!=0) l=min(n,d/c);
            if(l<=1 or 2*l-1==n-1) cout<<0<<"\n";
            else cout<<max(n-(2*l-1),0ll)<<"\n";
        }
    }
    return 0;
}
