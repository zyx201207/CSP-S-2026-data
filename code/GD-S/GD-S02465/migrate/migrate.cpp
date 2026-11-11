#include<bits/stdc++.h>
using namespace std;
const long long N=4e6+7,INF=1e18;
long long n,m,i,j,k,dp[N][3][2],a[N],la[N],d;
long long rf(__int128 w)
{
    long long l=0,r=n-1,mid=0,ans=0;
    for(;r>=l;)
    {
        mid=l+(r-l)/2;
        if(a[mid]<=w)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
long long as1=0,as3=0,as2=0;
long long f(long long w,long long o,long long p)
{
    if(w>=n||w==n-1) return 0;
    if(dp[w][o][p]!=-1) return dp[w][o][p];

    if(o==0)
    {
        as3=la[w]-w;
        as2=0;
        if(p==0) as1=la[w]-w;
        else as1=la[w]-la[w-1];
    }
    else if(o==1)
    {
        as3=la[w]-w;
        as1=la[w]-la[w-1];
        if(p==0) as2=la[w-1]-w;
        else as2=la[w-1]-la[w-2];
    }
    else if(o==2)
    {
        as3=la[w]-w;
        as1=0;
        if(p==0) as2=la[w]-w;
        else as2=la[w]-la[w-1];
    }
    if(as3<as1+as2)
    {
        //cout<<"!!!!!\n";return 0;
    }
    dp[w][o][p]=as2;
    if(as1==0&&as2==0) dp[w][o][p]+=0;
    else if(as1==1&&as3==1) dp[w][o][p]+=f(la[w],0,0);
    else if(as1>=2&&as3==2) dp[w][o][p]+=f(la[w],1,0);
    else if(as1==1&&as3!=1) dp[w][o][p]+=f(la[w],0,1);
    else if(as1>=2&&as3!=2) dp[w][o][p]+=f(la[w],1,1);
    else if(as1==0&&as2>=1&&as3==1) dp[w][o][p]+=f(la[w],2,0);
    else if(as1==0&&as2>=1&&as3!=1) dp[w][o][p]+=f(la[w],2,1);
    else cout<<as1<<" "<<as2<<" "<<as3<<"\n";
    return dp[w][o][p];
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long T;
    cin>>T>>T;
    for(;T>0;T--)
    {
        cin>>n>>d;
        for(i=0;i<n;i++) cin>>a[i];
        for(i=0;i<n;i++)
        {
            __int128 as=a[i]+d;
            la[i]=rf(as);
        }
        la[n-1]=n;
        for(i=0;i<=n;i++) for(j=0;j<3;j++) for(k=0;k<2;k++) dp[i][j][k]=-1;
        long long ans=0;
        for(i=n-1;i>=0;i--)
        {
            if(i==n-1){
                for(j=0;j<3;j++) for(k=0;k<2;k++) dp[i][j][k]=0;
            }
            else for(j=0;j<3;j++) for(k=0;k<2;k++) f(i,j,k);
            ans+=dp[i][0][0];
        }
        cout<<ans<<endl;
    }
    return 0;
}
//LGID=f_an_kaiyuan_
//shociACCSPT3 祭
