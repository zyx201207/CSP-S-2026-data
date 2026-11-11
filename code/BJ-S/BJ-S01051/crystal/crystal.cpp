#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],s[500010],n,m;
int solve(int x,int y){
    int l=1,r=y,res=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        //cout<<x<<" "<<y<<" "<<mid<<" "<<m<<" "<<x*(y-mid+1)<<" "<<s[y]<<" "<<s[mid-1]<<endl;
        if(m>=x*(y-mid+1)-(s[y]-s[mid-1])){
            //cout<<"Siu\n";
            res=mid;
            r=mid-1;
        }
        else{
            //cout<<"No\n";
            l=mid+1;
        }
    }
    return y-res+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        int tg=a[i];
        int cnt=solve(tg,i);
        //cout<<cnt<<endl;
        if(cnt!=-1) ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
