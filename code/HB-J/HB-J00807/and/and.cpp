#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m,a[N],sum,maxn;
//60
int main(){
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
            ll maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==2){
        ll ans=0,x=0,maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x!=0){
                    ans=ans&a[i];
                    x++;
                }
                if(x==0){
                    ans=a[i];
                    x++;
                }
                if(x==2){
                    maxx=max(maxx,ans);
                    x=0;
                    ans=0;
                }
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        ll ans=0,x=0,maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(x!=0){
                    ans=ans&a[i];
                    x++;
                }
                if(x==0){
                    ans=a[i];
                    x++;
                }
                if(x==2){
                    maxx=max(maxx,ans);
                    x=0;
                    ans=0;
                }
            }
        }
        cout<<maxx;
        return 0;
    }
    ll cnt=0;
    for(int i=0;i<(1<<n);i++){
            sum=0;
            cnt=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                if(cnt==0){
                    sum=a[j+1];
                }else{
                    sum=sum&a[j+1];
                }
                cnt++;
            }
            if(cnt==m){
                maxn=max(maxn,sum);
                break;
            }
        }
    }
    cout<<maxn;
    return 0;
}
