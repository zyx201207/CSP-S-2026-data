#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,Ans,ans;
int a[500010],sum[500010];
bool cmp(int x,int y){
    return x<y;
}
bool check(int x,int y,int k){
    int num=y-x+1;
    int need=num*k-(sum[y]-sum[x-1]);
    //cout<<x<<" "<<y<<" "<<need<<endl;
    if(need>m){
        return false;
    }
    else{
        return true;
    }
}
signed main(){
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
    for(int i=1;i<=n;i++){//当a[i]作为基准值时，大的不用考虑，如果有相等的也没有事情
        int l=1,r=i;
        Ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i-1,a[i])){
                r=mid-1;
                Ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        //cout<<Ans<<endl;
        ans=max(ans,(i-Ans+1));
    }
    cout<<ans;
    return 0;
}
