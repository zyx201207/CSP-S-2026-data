#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

const int N=5e5+10;
const int INF=1e7;

int n;
LL m;
LL a[N];

LL sum[N];
int find(int R){
    int l=1,r=R,res=INF;
    while(l<=r){
        int mid=(l+r)>>1;
        LL s=a[R+1]*(R-mid+1)-(sum[R]-sum[mid-1]);
        if(s<=m) r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
int ans;

int main(){
    freopen("crystal.in","r",stdin);
//    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+n+1);

    for(int i=1;i<=n;){
        int cnt=0,t=i;
        while(t<=n && a[i]==a[t]) sum[t]=sum[t-1]+a[t],t++,cnt++;
        t--;

        int res=find(i-1);
        ans=max(ans,cnt-1+i-res+1);

//        cout<<"i= "<<i<<", t= "<<t<<", res= "<<res<<", cnt="<<cnt<<", ans= "<<ans<<"\n";

        i=t+1;
    }

    printf("%d\n",ans);
    return 0;
}
