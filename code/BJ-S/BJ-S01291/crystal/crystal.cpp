#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N=5e5+5;
int n,m;
int a[N];
int dif[N];
int sum[N],sum2[N],ans=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    per(i,n-1,1) dif[i]=a[i+1]-a[i];
    dif[n]=0;
    per(i,n,1) sum[i]=sum[i+1]+dif[i];
    per(i,n,1) sum2[i]=sum2[i+1]+sum[i];
    //rep(i,1,n) cout<<dif[i]<<' ';
    //cout<<'\n';
    //rep(i,1,n) cout<<sum[i]<<' ';
    //cout<<'\n';
    //rep(i,1,n) cout<<sum2[i]<<' ';
    //cout<<'\n';
    int j=1;
    rep(i,1,n)
    {
        while(j<=i&&sum2[j]-sum2[i]-sum[i]*(i-j)>m)
        {
            j++;
        }
        if(j<=i)
        {
            ans=max(ans,i-j+1);
            //cout<<"over\n";
            //cout<<sum2[j]<<" "<<sum2[i]<<" "<<sum[i]*(i-j)<<'\n';
            //cout<<"w:"<<sum2[j]-sum2[i]-sum[i]*(i-j)<<'\n';
            //cout<<i<<" "<<j<<" "<<i-j+1<<'\n';
        }

    }
    cout<<ans;
    return 0;

}

