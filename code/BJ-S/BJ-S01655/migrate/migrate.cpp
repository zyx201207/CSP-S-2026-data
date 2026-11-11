#include<iostream>
#include<vector>
#define int long long
using namespace std;
int cid,t,n,d;
const int nr=2e6+10;
int a[nr],pl[nr],pr[nr];
int lst[nr],nxt[nr];
int cnt2[nr],cnt3[nr];
int Rl[nr],Rr[nr];
int cntl[nr],cntr[nr],s[nr];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>cid>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int pos=0;
        for(int i=1;i<=n;i++)
        {
            while(pos<n&&a[pos+1]-a[i]<=d)pos++;
            pr[i]=pos;
        }
        pos=n+1;
        for(int i=n;i>=1;i--)
        {
            while(pos>1&&a[i]-a[pos-1]<=d)pos--;
            pl[i]=pos;
        }
        for(int i=1;i<=n;i++)lst[i]=nxt[i]=0;
        for(int i=1;i<=n;i++)if(pl[pr[i]]==i)nxt[i]=pr[i],lst[pr[i]]=i;
        //type 2
        pos=0;
        for(int i=1;i<=n;i++)
        {
            pos=max(pos,pl[i]-1);
            while(pos<i&&pr[pos+1]==i)pos++;
            cnt2[i]=pos-pl[i]+1;
        }
        //type 3
        pos=n+1;
        for(int i=n;i>=1;i--)
        {
            pos=min(pos,pr[i]+1);
            while(pos>i&&pl[pos-1]==i)pos--;
            cnt3[i]=pr[i]-pos+1;
        }
        for(int i=1;i<=n;i++)
        {
            Rl[i]=Rr[i]=0;
            if(pr[i]<=i+1)continue;
            Rl[i]=pr[pr[i]-2]+1,Rr[i]=pr[pr[i]-1];
            Rl[i]=max(Rl[i],pr[i]+1);
        }
        /*or(int i=1;i<=n;i++)cout<<pl[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cout<<pr[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cout<<cnt2[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cout<<cnt3[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cout<<i<<" "<<Rl[i]<<" "<<Rr[i]<<endl;
        for(int i=1;i<=n;i++)cout<<i<<" ,"<<lst[i]<<" "<<nxt[i]<<endl;*/
        for(int i=1;i<=n;i++)cntl[i]=cntr[i]=0;
        for(int i=1;i<=n;i++)
            if(!lst[i])
            {
                int now=i;
                cntl[i]=0;
                while(nxt[now])
                {
                    cntl[nxt[now]]=cntl[now]+cnt2[nxt[now]];
                    now=nxt[now];
                }
            }
        for(int i=n;i>=1;i--)
            if(!nxt[i])
            {
                int now=i;
                cntr[i]=0;
                while(lst[now])
                {
                    cntr[lst[now]]=cntr[now]+cnt3[lst[now]];
                    now=lst[now];
                }
            }
        // for(int i=1;i<=n;i++)cout<<i<<" "<<cntl[i]<<" "<<cntr[i]<<endl;
        int ans=0;
        //both sides can expand
        for(int i=1;i<=n;i++)
        {
            if(pr[i]==i)continue;
            int j=pr[pr[i]];
            if(j==pr[i])continue;
            if(pl[j]!=pr[i]-1)continue;
            if(pl[pl[j]]!=i)continue;
            ans+=cntl[i]*cntr[j];
            //cout<<i<<" "<<j<<" "<<cntl[i]*cntr[j]<<endl;
        }
        // cout<<ans<<endl;
        //left side cannot expand
        for(int i=1;i<=n;i++)
        {
            if(pr[i]==i)continue;
            int j=pr[pr[i]];
            if(j==pr[i])continue;
            if(pl[j]!=pr[i]-1)continue;
            ans+=cntr[j];
            // cout<<j<<": "<<cntr[j]<<endl;
        }
        // cout<<ans<<endl;
        //right side cannot expand
        for(int i=1;i<=n;i++)
        {
            if(pl[i]==i)continue;
            int j=pl[pl[i]];
            if(j==pl[i])continue;
            if(pr[j]!=pl[i]+1)continue;
            ans+=cntl[j];
        }
        //cout<<ans<<endl;
        //no side can expand
        for(int i=1;i<=n;i++)
            if(Rl[i])
            {
                ans+=Rr[i]-Rl[i]+1;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
