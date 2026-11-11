#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=-1;
long long m,a[N],sum[N],minn=0x3f3f3f3f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        //long long diff=i*a[i]-sum[i]+a[i];
        int l=1,r=i,x;
        int cnt=n+1;
        while(l<=r){
            int x=(l+r)/2;
            if(a[i]*(i-x+1)-(sum[i]-sum[x-1])<=m){//a[i]*(i-x+1)-(sum[i]-sum[x-1])<=m
                cnt=x;
                r=x-1;
            }
            else l=x+1;
        }
        ans=max(i-cnt+1,ans);
    }
    cout<<ans<<'\n';
    return 0;
}
