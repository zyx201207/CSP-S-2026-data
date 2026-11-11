#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=0,gc;
bool flag=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
    }
    if(flag){
        gc=a[2]-a[1];
        for(int i=1;m-i*gc>=0;i++){
            if(ans+1>=n)break;
            ans++;
            m-=i*gc;
        }
        cout<<ans+1;
    }
    else{
        for(int i=2;i<=n;i++){
                int cnt=1,m2=m;
            for(int j=i-1;j>=1;j--){
                if(m2>=(a[i]-a[j])){
                    cnt++;
                    m2-=(a[i]-a[j]);
                }
                else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
