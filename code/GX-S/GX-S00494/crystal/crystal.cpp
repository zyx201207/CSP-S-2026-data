#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    long long ans=0;
    long long ha,hs=1;
    cin>>n>>m;
    long long a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i-1]==a[i]){
            hs++;
            ha=a[i];
        }
    }
    if(m==0){
        cout<<hs<<'\n';
        return 0;
    }
    int cnt=0;
    for(int i=n;i>=1;i--){
        if(hs>1){
            while(a[i]<ha){
                cnt=cnt+(ha-a[i]);
                ans++;
                break;
            }
        }else if(hs==1){
            while(a[i]<a[n/2+1]){
                int mid=a[n/2+1];
                cnt=cnt+mid-a[i];
                ans++;
                break;
            }
        }
        if(cnt==m){
            if(hs>1){
                cout<<ans+hs<<'\n';
            }else if(hs==1) cout<<ans+1<<'\n';
        }
    }
    return 0;
}
