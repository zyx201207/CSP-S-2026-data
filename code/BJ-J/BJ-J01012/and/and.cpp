#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],ans;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(m==1){

        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ll ma=(a[i]&a[j]);
                ans=max(ans,ma);
            }
        }
        cout<<ans;

        return 0;
    }
    if(m==3){
        ll cnt=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ll ma=(a[i]&a[j]);
                for(int k=1;k<=n;k++){
                    if(k!=i&&k!=j)cnt=(ma&a[k]);
                    ans=max(ans,cnt);

                }
            }
        }

        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    if(m==n-1){
        ll ma;
        for(int i=1;i<=n;i++){
            if(i==1)ma=a[2];
            else ma=a[1];
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                ma=(ma&a[j]);
            }
            ans=max(ans,ma);

        }
        cout<<ans;
        return 0;
    }
    cout<<a[n];
    return 0;
}
