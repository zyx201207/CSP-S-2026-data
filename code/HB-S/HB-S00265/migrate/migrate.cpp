#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=3e18+7;
int C,T,n,nxt[5000005];
ll d,arr[5000005],cnt[5000005],minn[5000005];
ll read()
{
    char ch=getchar_unlocked();
    ll sign=1,inp=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') sign=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9')
    {
        inp=inp*10+ch-'0';
        ch=getchar_unlocked();
    }
    return inp*sign;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        int r=1,ans=0;;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=n;i++)
        {
            while(r+1<=n&&arr[i]+d>=arr[r+1]) ++r;
            nxt[i]=r;
        }
        for(int k=1;k<=n;k++)
        {
            //cout<<nxt[k]<<' ';
            for(int i=k+1;i<=n;i++) minn[i]=INF,cnt[i]=0;
            cnt[k]=1,minn[k]=0;
            for(int i=k;i<=n;i++)//qidian
            {
                if(minn[i]==INF) break;
                if(cnt[i]==2) ++ans;
                //if(cnt[i]>2) break;
                for(int j=i+1;j<=nxt[i];j++)
                {
                    //if(j==n) cout<<minn[n]<<' ';

                    if(minn[j]<minn[i]+1) continue;
                    //if(j==n) cout<<cnt[j]<<' '<<cnt[i];
                    minn[j]=minn[i]+1;
                    if(minn[j]==minn[i]+1) cnt[j]+=cnt[i];
                }
            }
            //cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
