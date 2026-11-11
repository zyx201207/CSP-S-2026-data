#include <bits/stdc++.h>
using namespace std;
// I can use NDEBUG, but I think a explicit macro will be more convenient
// and I can switch-off some other check codes
// well, it's useless because I delete all assert
// #define CHECK // only debug-time
int C,t,n;
long long d;
long long a[2000005];
int le[2000005],ri[2000005];
vector<int> ple[2000005],pri[2000005];
long long st[2000005],ed[2000005];
int pr[2000005],nx[2000005];
int pr2[2000005],nx2[2000005];
int ds[305][305],cnt[305][305];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>C>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            ple[i].clear(),pri[i].clear();
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        {
            int lpos=1,rpos=1;
            for(int i=1;i<=n;i++)
            {
                while(a[i]-a[lpos]>d)
                    lpos++;
                while(rpos<n&&a[rpos+1]-a[i]<=d)
                    rpos++;
                le[i]=lpos,ri[i]=rpos;
                ple[le[i]].push_back(i);
                pri[ri[i]].push_back(i);
            }
        }
        {
            int pxl=1,pxr=1;
            for(int i=1;i<=n;i++)
            {
                while(pxl<=n&&a[pxl]<a[i]-d)
                    pxl++;
                while(pxr<=i&&a[pxr]<a[ri[i]]-d)
                    pxr++;
                pr[i]=pxr-pxl;
                // cout<<i<<" ["<<pxl<<" "<<pxr<<")"<<endl;
            }
        }
        if((C>=1&&C<=6)||n<=300)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    ds[i][j]=0x3f3f3f3f,cnt[i][j]=0;
            for(int i=1;i<=n;i++)
                ds[i][i]=0;
            for(int i=1;i<=n;i++)
                for(int j=le[i];j<=ri[i];j++)
                    if(j!=i)
                        ds[i][j]=1,cnt[i][j]=1;
            for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                    {
                        if(ds[i][k]+ds[k][j]<ds[i][j])
                        {
                            ds[i][j]=ds[i][k]+ds[k][j];
                            cnt[i][j]=min(cnt[i][j]+cnt[i][k]*cnt[k][j],3);
                        }
                        else if(ds[i][k]+ds[k][j]==ds[i][j])
                            cnt[i][j]=min(cnt[i][j]+cnt[i][k]*cnt[k][j],3);
                    }
            long long ans=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(cnt[i][j]==2)
                        ans++;
            cout<<ans<<"\n";
            continue;
        }
        {
            int pxl=1,pxr=1;
            for(int i=1;i<=n;i++)
            {
                while(pxl<=n&&a[pxl]<a[i]-d)
                    pxl++;
                while(pxr<=i&&a[pxr]<a[ri[i]-1]-d)
                    pxr++;
                pr2[i]=pxr-pxl;
                // cout<<i<<" ["<<pxl<<" "<<pxr<<")"<<endl;
            }
        }
        {
            int pxl=n,pxr=n;
            for(int i=n;i>=1;i--)
            {
                while(pxl>i&&a[pxl]>a[le[i]]+d)
                    pxl--;
                while(pxr>=1&&a[pxr]>a[i]+d)
                    pxr--;
                nx[i]=pxr-pxl;
                // cout<<i<<" ("<<pxl<<" "<<pxr<<"]"<<endl;
            }
        }
        {
            int pxl=n,pxr=n;
            for(int i=n;i>=1;i--)
            {
                while(pxl>i&&a[pxl]>a[le[i]+1]+d)
                    pxl--;
                while(pxr>=1&&a[pxr]>a[i]+d)
                    pxr--;
                nx2[i]=pxr-pxl;
                // cout<<i<<" ("<<pxl<<" "<<pxr<<"]"<<endl;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ed[i]=0; // at least 1 move
            for(int j:pri[le[i]])
                if(j!=i)
                    ed[i]+=ed[j]+(1+pr[j]);
        }
        for(int i=n;i>=1;i--)
        {
            st[i]=0;
            for(int j:ple[ri[i]])
                if(j!=i)
                    st[i]+=st[j]+(1+nx[j]);
        }
        for(int i=1;i<=n;i++)
        {
            if(ri[i]-1>i)
                for(int j:ple[ri[i]-1])
                    if(j!=i)
                        ans+=(long long)(ed[i]+pr2[i]+1)*(st[j]+nx2[j]+1); // ,cout<<i<<" "<<j<<" "<<(ed[i]+pr2[i]+1)*(st[j]+nx2[j]+1)<<endl;
        }
        cout<<ans<<"\n";
    }
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

7 5
0 4 6 7 10 11 15

4->10
0->10
4->11
0->11
7->15
// no 4->15
6->15
// how to deal with multiple mat
*/
/*
14:28 The password is "Oct31==Dec25?", what a password with homour that I don't think Cn Com-puter Found-ation have.
14:40 Finish T1, all case passed!
Debug arbiter for selfeval for several minutes
14:50 Reading and thinking T2...
14:59 I think I get T2's key, that why the weird meanings of n and m, because actually n is the number of point in right graph.
15:13 Finish T2, debugging...
15:21 Finish T2, all case passed!
15:29 Thinking T3...
15:35 Well, I think I can split a two-ways link into u.1.x w z y.1.v, where y-x>d, z-x<=d, y-w<=d
15:41 I think I have a (fumble?) ways to solve T3.
PS: I have see this in the name of cases of an Atcoder problem.
PS: They are: hand, fumble, kill, nightmare(some may not exact, like miss -ing or -s).
16:07 I have solve ed1 and st1, it's not enough to solve this problem, but I think I'm getting closer to the solution, just need a few more steps.
16:11 I think I have write the solution, but it needs more tests and debugging.
16:14 It fails on test case 1-2, why?
16:59 Now it pass all small case but all 0 on big case, WHY???
18:00 T3 is FALSE
18:00 What the heck, the last two problem is too hard for me
*/
