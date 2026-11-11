#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],s[500005];
int n,m,ans=0;
bool cmp(int a,int b){
    return a>b;
}
bool check(){
    int flag=0;
    int tmp=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=tmp){
            return 0;
        }
        tmp=a[i]-a[i-1];
    }
    return 1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(check()){
        sort(a+1,a+n+1,cmp);
        int cnt=0,tmp=a[1];
        for(int i=1;i<=n;i++){
            if(cnt+tmp-a[i]<=m){
                cnt=cnt+tmp-a[i];
                ans++;
            }else break;
        }
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        int mid;
        while(l<r){
            mid=(l+r)/2;
            int tmp=a[i]*(i-mid+1)-s[i]+s[mid-1];
            if(tmp<=m){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<'\n';
    return 0;
}
