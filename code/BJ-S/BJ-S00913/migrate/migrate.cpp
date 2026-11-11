#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int n,d;
int a[N];
int fl[N],fr[N],cntl[N],cntr[N];
void work()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i],cntl[i]=cntr[i]=0;
    for(int i=1;i<=n;i++)
    {
        fl[i]=fr[i]=i;
        for(int k=(1ll<<30);k;k>>=1)
        {
            if(fl[i]-k>=1)if(a[i]-a[fl[i]-k]<=d)fl[i]-=k;
            if(fr[i]+k<=n)if(a[fr[i]+k]-a[i]<=d)fr[i]+=k;
        }
        //cout<<i<<' '<<fl[i]<<' '<<fr[i]<<'\n';
    }
    int ans=0;

    for(int i=1,b,c;i<n;i++)
    {
        b=i,c=i+1;
        if(fl[c]>fl[b])cntl[b]=(fl[c]-fl[b]+cntl[fl[b]]);
        else cntl[b]=0;
    }if(fl[n]<n)cntl[n]=n-fl[n]+cntl[fl[n]];else cntl[n]=0;

    for(int i=n,a,b;i>1;i--)
    {
        a=i-1,b=i;
        if(fr[b]>fr[a])cntr[b]=(fr[b]-fr[a]+cntr[fr[b]]);
        else cntr[b]=0;
    }if(fr[1]>1)cntr[1]=fr[1]-1+cntr[fr[1]];else cntr[1]=0;

    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<' '<<cntl[i]<<' '<<cntr[i]<<'\n';
    }*/

    for(int i=1,a,b,c,d;i+3<=n;i++)
    {
        a=i,b=i+1,c=i+2,d=i+3;
        int A=fr[a],B=fr[b],C=fl[c],D=fl[d];
        if(A<=c)A=c;
        if(D>=b)D=b;
        if(D<=C||A>=B)continue;
        ans+=(D-C+cntl[C])*(B-A+cntr[B]);
        //ans+=(cntl[D-1]-cntl[C-1])*(cntr[A+1]-cntr[B+1]);
        //cout<<b<<' '<<c<<' '<<D<<' '<<C<<' '<<A<<' '<<B<<' '<<(D-C+cntl[C])<<' '<<(B-A+cntr[B])<<'\n';
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);//6
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)work();
    return 0;
}

