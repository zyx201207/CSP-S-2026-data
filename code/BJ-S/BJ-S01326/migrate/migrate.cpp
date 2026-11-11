//pts in optimistic:56
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define sc second
#define pb push_back
#define pii pair<int,int>
#define vec vector
using namespace std;
const int N=5e3+5,M=2e6+5;
int c,T;
int n,d,x[M],dp[M],srt[N],L[M];
void solve1()
{
    cin>>n>>d;
    For(i,1,n)
        cin>>x[i];
    if(n==1)
        return cout<<0<<'\n',void();
    int ans=0;
    For(i,1,n)
    {
        For(j,1,n)
            dp[j]=0,srt[j]=-1;
        dp[i]=1,srt[i]=0;
        int lst=i;
        For(j,i+1,n)
        {
            if(x[j]-x[j-1]>d)
                break;
            if(x[lst]+d>=x[j])
                srt[j]=srt[lst]+1,L[j]=lst;
            else
            {
                srt[j]=srt[j-1]+1;
                lst=j-1;
                L[j]=lst;
            }
            // cout<<i<<' '<<j<<' '<<srt[j]<<'\n';
        }
        For(j,i+1,n)
        {
            if(x[j]-x[L[j]]<=d)
                dp[j]+=dp[L[j]];
            if(L[j]-1>=1&&x[j]-x[L[j]-1]<=d&&srt[L[j]-1]+1==srt[j])
                dp[j]+=dp[L[j]-1];
            if(L[j]-2>=1&&x[j]-x[L[j]-2]<=d&&srt[L[j]-2]+1==srt[j])
                dp[j]+=dp[L[j]-2];
            if(dp[j]==2)
                ans++;
            // cout<<i<<' '<<j<<' '<<L[j]<<' '<<srt[j]<<' '<<dp[j]<<'\n';
        }
    }
    cout<<ans<<'\n';
    return;
}
void solve2()
{
    // cout<<114514<<'\n';
    cin>>n>>d;
    For(i,1,n)
        cin>>x[i];
    if(n==1)
        return cout<<0<<'\n',void();
    int cha=x[2]-x[1];
    int k=d/cha;
    if(k<=1)
        return cout<<0<<'\n',void();
    int p=2*k-1;
    cout<<max(0ll,n-p)<<'\n';
}
void solve3()
{
    cin>>n>>d;
    For(i,1,n)
        cin>>x[i];
    if(n==1)
        return cout<<0<<'\n',void();
    int pos=1,ans=0,l=1,r=1;
    For(i,1,n)
    {
        while(pos<n&&x[pos+1]<=x[i]+d)
            pos++;
        if(pos==i+1)
            continue;
        while(r<n&&x[r+1]-x[pos-1]<=d)
            r++;
        while(l<n&&x[l+1]-x[pos-2]<=d)
            l++;
        if(l==n)
            break;
        ans+=r-l;
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>c>>T;
    while(T--)
    {
        // cout<<T<<'\n';
        if(c<=10)
            solve1();
        else if(c<=12)
            solve2();
        else if(c<=14)
            solve3();
        // else if(c<=18)
        //     solve4();
    }
    return 0;
}